#include "kalorii.h"
#include "ui_kalorii.h"
#include "portion_info.h"
#include <QMessageBox>

kalorii::kalorii(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::kalorii)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &kalorii::onCalculateCalories);
}

kalorii::~kalorii()
{
    delete ui;
}

void kalorii::onCalculateCalories()
{
    double caloriesPer100g = ui->caloriesLineEdit->text().toDouble();
    double weight = ui->weightLineEdit->text().toDouble();
    double fatPer100g = ui->fatLineEdit->text().toDouble();


    if (!caloriesPer100g || !weight || !fatPer100g) {
        QMessageBox::warning(this, "Некорректный ввод данных",
            "Пожалуйста, введите числовые значения для количества калорий, вес порции и количество жиров.");
        return;
    }

    if (caloriesPer100g == 0 || weight == 0 || fatPer100g == 0) {
        QMessageBox::warning(this, "Ошибка ввода", "Пожалуйста, заполните все поля корректно.");
        return;
    }

    if (caloriesPer100g > 1000000 || weight > 1000000 || fatPer100g > 1000000) {
        QMessageBox::warning(this, "Ошибка ввода",
            "Значения не могут быть больше 1 000 000. Пожалуйста, введите корректные значения.");
        return;
    }

    FoodItem item(caloriesPer100g, weight, fatPer100g);
    double totalCalories = item.calculateCalories();
    double totalFat = item.calculateFat();

    ui->resultLabel->setText(
        QString("Калорийность порции: %1 ккал\nЖиры в порции: %2 г").arg(totalCalories).arg(totalFat)
    );
}
