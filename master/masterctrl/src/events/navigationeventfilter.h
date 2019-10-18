#ifndef NAVIGATIONEVENTFILTER_H
#define NAVIGATIONEVENTFILTER_H

#include <QDebug>
#include <QKeyEvent>
#include <QObject>

class NavigationEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit NavigationEventFilter(QObject *parent = nullptr);

signals:
    void keyEvent(int key, bool state);
    void keyPressed(int key);
    void keyReleased(int key);

public slots:

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:

};

#endif // NAVIGATIONEVENTFILTER_H
