#ifndef lync_telepathyTEST_H
#define lync_telepathyTEST_H

#include <QtCore/QObject>

class lync_telepathyTest : public QObject
{
Q_OBJECT
private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();

    void someTest();
};

#endif // lync_telepathyTEST_H
