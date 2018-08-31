#ifndef TESTKEYHANDLER_H
#define TESTKEYHANDLER_H

#include <QObject>

class TestKeyHandler : public QObject
{
    Q_OBJECT
public:
    explicit TestKeyHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TESTKEYHANDLER_H