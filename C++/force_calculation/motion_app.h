#ifndef MOTION_APP_H
#define MOTION_APP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MotionApp; }
QT_END_NAMESPACE

class MotionApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit MotionApp(QWidget* parent = nullptr);
    ~MotionApp();

private slots:
    void onCalculate();

private:
    Ui::MotionApp* ui;
};

#endif
