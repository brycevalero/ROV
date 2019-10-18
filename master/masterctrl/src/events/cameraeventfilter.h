#ifndef CAMERAEVENTFILTER_H
#define CAMERAEVENTFILTER_H

#include <QDebug>
#include <QKeyEvent>
#include <QObject>

class CameraEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit CameraEventFilter(QObject *parent = nullptr);

signals:
    void keyEvent(int key, bool state);
    void keyPressed(int key);
    void keyReleased(int key);

public slots:

protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:

};

#endif // CAMERAEVENTFILTER_H
