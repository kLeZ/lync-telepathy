#include <TelepathyQt/Debug>
#include <TelepathyQt/Constants>
#include <TelepathyQt/Types>

#include <QCoreApplication>

#include <QDebug>
#include <QtCore>

#include "protocols.h"
#include "lync-telepathy.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    Tp::registerTypes();
    Tp::enableDebug(false);
    Tp::enableWarnings(false);

    Protocols protocols;

    return app.exec();
}
