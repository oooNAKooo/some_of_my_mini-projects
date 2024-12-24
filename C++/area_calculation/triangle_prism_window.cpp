#include "triangle_prism_window.h"
#include "ui_triangle_prism_window.h"
#include "prism.h"
#include <QMessageBox>

TrianglePrismWindow::TrianglePrismWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::TrianglePrismWindow)
{
    ui->setupUi(this);

    connect(ui->calculateButton, &QPushButton::clicked, this, &TrianglePrismWindow::onCalculateAreaAndVolume);
}

TrianglePrismWindow::~TrianglePrismWindow()
{
    delete ui;
}

void TrianglePrismWindow::onCalculateAreaAndVolume()
{
    double side1 = ui->side1LineEdit->text().toDouble();
    double side2 = ui->side2LineEdit->text().toDouble();
    double height = ui->heightLineEdit->text().toDouble();

    Prism prism(side1, side2, height);
    double area = prism.calculateArea();
    double volume = prism.calculateVolume();

    ui->resultLabel->setText(QString("Площадь треугольника: %1 m²\nПлощадь призмы: %2 m³").arg(area).arg(volume));
}
