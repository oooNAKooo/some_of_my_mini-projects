#ifndef UI_KALORII_H
#define UI_KALORII_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_kalorii
{
public:
    QWidget* centralWidget;
    QLineEdit* caloriesLineEdit;  
    QLineEdit* weightLineEdit;     
    QLineEdit* fatLineEdit;        
    QPushButton* pushButton;       
    QLabel* resultLabel;          
    QVBoxLayout* layout;

    void setupUi(QMainWindow* kalorii)
    {
        if (kalorii->objectName().isEmpty())
            kalorii->setObjectName("kalorii");
        kalorii->resize(400, 300);

        centralWidget = new QWidget(kalorii);
        centralWidget->setObjectName("centralWidget");

        caloriesLineEdit = new QLineEdit(centralWidget);
        caloriesLineEdit->setObjectName("caloriesLineEdit");
        caloriesLineEdit->setPlaceholderText("Введите калорийность на 100 г");

        weightLineEdit = new QLineEdit(centralWidget);
        weightLineEdit->setObjectName("weightLineEdit");
        weightLineEdit->setPlaceholderText("Введите вес порции (г)");

        fatLineEdit = new QLineEdit(centralWidget);
        fatLineEdit->setObjectName("fatLineEdit");
        fatLineEdit->setPlaceholderText("Введите жиры на 100 г");

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setText("Рассчитать");

        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setText("Результат будет показан здесь");

        layout = new QVBoxLayout(centralWidget);
        layout->addWidget(caloriesLineEdit);
        layout->addWidget(weightLineEdit);
        layout->addWidget(fatLineEdit);
        layout->addWidget(pushButton);
        layout->addWidget(resultLabel);

        kalorii->setCentralWidget(centralWidget); 
    }

    void retranslateUi(QMainWindow* kalorii)
    {
        kalorii->setWindowTitle(QCoreApplication::translate("kalorii", "Калькулятор калорийности и жиров", nullptr));
    }
};

namespace Ui {
    class kalorii : public Ui_kalorii {};
}

QT_END_NAMESPACE

#endif
