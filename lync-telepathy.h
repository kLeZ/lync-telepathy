#ifndef lync_telepathy_H
#define lync_telepathy_H

#include <QtCore/QObject>

class lync_telepathy : public QObject
{
Q_OBJECT
public:
    lync_telepathy();
    virtual ~lync_telepathy();
};

#endif // lync_telepathy_H
