#include "motion_app.h"
#include "ui_motion_app.h"
#include "physics_object.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include <QIntValidator>

MotionApp::MotionApp(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MotionApp)
{
    ui->setupUi(this);

    // Устанавливаем валидаторы для строк ввода
    ui->speedLineEdit->setValidator(new QDoubleValidator(0, 1000000, 2, this)); 
    ui->timeLineEdit->setValidator(new QIntValidator(0, 1000000, this));        
    ui->forceLineEdit->setValidator(new QDoubleValidator(0, 1000000, 2, this)); 

    connect(ui->pushButton, &QPushButton::clicked, this, &MotionApp::onCalculate);
}

MotionApp::~MotionApp()
{
    delete ui;
}

void MotionApp::onCalculate()
{
    bool speedOk, timeOk, forceOk;

    double speed = ui->speedLineEdit->text().toDouble(&speedOk);
    int timeMinutes = ui->timeLineEdit->text().toInt(&timeOk);
    double force = ui->forceLineEdit->text().toDouble(&forceOk);

    if (!speedOk || !timeOk || !forceOk) {
        QMessageBox::warning(this, "Некорректный ввод данных",
            "Пожалуйста, введите числовые значения для скорости, времени и силы.");
        return;
    }

    if (speed > 1000000 || timeMinutes > 1000000 || force > 1000000) {
        QMessageBox::warning(this, "Ошибка ввода",
            "Значения не могут быть больше 1 000 000. Пожалуйста, введите корректные значения.");
        return;
    }

    WorkObject object(speed, timeMinutes, force);
    double distance = object.calculateDistance();
    double workDone = object.calculateWork();

    ui->resultLabel->setText(QString("Расстояние: %1 m, Количество работы: %2 J").arg(distance).arg(workDone));
}
