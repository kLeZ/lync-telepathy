#include <QCoreApplication>
#include "lync-telepathy.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    lync_telepathy foo;
    return app.exec();
}
