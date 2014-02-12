/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  Alessandro Accardo <julius8774@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "cm-wrapper.h"

#include <TelepathyQt/Debug>
#include <TelepathyQt/ConnectionManager>
#include <TelepathyQt/PendingReady>

#include <QDebug>

CMWrapper::CMWrapper(const QString &cmName, QObject *parent)
    : QObject(parent),
      mCM(ConnectionManager::create(cmName))
{
    connect(mCM->becomeReady(),
            SIGNAL(finished(Tp::PendingOperation *)),
            SLOT(onCMReady(Tp::PendingOperation *)));
}

CMWrapper::~CMWrapper()
{
}

ConnectionManagerPtr CMWrapper::cm() const
{
    return mCM;
}

void CMWrapper::onCMReady(PendingOperation *op)
{
    if (op->isError()) {
        qWarning() << "CM" << mCM->name() << "cannot become ready -" <<
            op->errorName() << ": " << op->errorMessage();
        return;
    }

    qDebug() << "CM" << mCM->name() << "ready!";
    qDebug() << "Supported protocols:";
    foreach (const QString &protocol, mCM->supportedProtocols()) {
        qDebug() << "\t" << protocol;
    }

    emit finished();
}

#include "cm-wrapper.moc"