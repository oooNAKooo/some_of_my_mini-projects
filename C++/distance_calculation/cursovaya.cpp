#include "cursovaya.h"
#include "ui_cursovaya.h"
#include "moving_object.h"
#include <QMessageBox>

cursovaya::cursovaya(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::cursovaya)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &cursovaya::onCalculateDistance);
}

cursovaya::~cursovaya()
{
    delete ui;
}

void cursovaya::onCalculateDistance()
{
    int minutes = ui->minutesLineEdit->text().toInt();
    int seconds = ui->secondsLineEdit->text().toInt();
    double speed = ui->speedLineEdit->text().toDouble();

    MovingObject object(minutes, seconds, speed);
    double distance = object.calculateDistance();

    ui->resultLabel->setText(QString("Пройденное расстояние: %1 м").arg(distance));
}
