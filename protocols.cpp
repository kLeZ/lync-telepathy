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

#include "protocols.h"

#include <TelepathyQt/Debug>
#include <TelepathyQt/ConnectionManager>
#include <TelepathyQt/PendingStringList>

#include <QCoreApplication>
#include <QDebug>

Protocols::Protocols()
    : cmWrappersFinished(0)
{
    qDebug() << "Listing names";
    connect(ConnectionManager::listNames(),
            SIGNAL(finished(Tp::PendingOperation *)),
            SLOT(onListNamesFinished(Tp::PendingOperation *)));
}

Protocols::~Protocols()
{
}

void Protocols::onListNamesFinished(PendingOperation *op)
{
    if (op->isError()) {
        qWarning() << "Error listing connection manager names -" <<
            op->errorName() << ": " << op->errorMessage();
        return;
    }

    PendingStringList *ps = qobject_cast<PendingStringList *>(op);

    qDebug() << "Supported CMs:" << ps->result();

    foreach (const QString &cmName, ps->result()) {
        CMWrapper *cmWrapper = new CMWrapper(cmName, this);
        mCMWrappers.append(cmWrapper);
        connect(cmWrapper,
                SIGNAL(finished()),
                SLOT(onCMWrapperFinished()));
    }
}

void Protocols::onCMWrapperFinished()
{
    if (++cmWrappersFinished == mCMWrappers.size()) {
        QCoreApplication::quit();
    }
}

#include "protocols.moc"