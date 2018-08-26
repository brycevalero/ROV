#ifndef XGAMEPAD_H
#define XGAMEPAD_H

#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadManager>
#include <QLoggingCategory>

#include "master/masterlib_global.h"

class QGamepad;

class MASTERLIBSHARED_EXPORT XGamepad : public QObject
{
    Q_OBJECT

public:
    explicit XGamepad(QObject *parent = 0);
        ~XGamepad();

    private:
        QGamepad *m_gamepad;
};

#endif // XGAMEPAD_H
