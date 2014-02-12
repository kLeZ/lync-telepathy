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

#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include <TelepathyQt/Types>

#include "cm-wrapper.h"

#include <QList>
#include <QObject>

using namespace Tp;

namespace Tp
{
class PendingOperation;
}

class Protocols : public QObject
{
    Q_OBJECT

public:
   Protocols();
   ~Protocols();

private Q_SLOTS:
    void onListNamesFinished(Tp::PendingOperation *op);
    void onCMWrapperFinished();

private:
    QList<CMWrapper *> mCMWrappers;
    int cmWrappersFinished;
};

#endif // PROTOCOLS_H
