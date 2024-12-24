#ifndef UI_cursovaya_H
#define UI_cursovaya_H

#include <QCoreApplication>
#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_cursovaya
{
public:
    QWidget* centralWidget;
    QLineEdit* minutesLineEdit;   
    QLineEdit* secondsLineEdit;   
    QLineEdit* speedLineEdit;     
    QPushButton* pushButton;    
    QLabel* resultLabel;          
    QVBoxLayout* layout;

    void setupUi(QMainWindow* cursovaya)
    {
        if (cursovaya->objectName().isEmpty())
            cursovaya->setObjectName("cursovaya");
        cursovaya->resize(400, 300);

        centralWidget = new QWidget(cursovaya);
        centralWidget->setObjectName("centralWidget");

        minutesLineEdit = new QLineEdit(centralWidget);
        minutesLineEdit->setObjectName("minutesLineEdit");
        minutesLineEdit->setPlaceholderText("Введите минуты");

        secondsLineEdit = new QLineEdit(centralWidget);
        secondsLineEdit->setObjectName("secondsLineEdit");
        secondsLineEdit->setPlaceholderText("Введите секунды");

        speedLineEdit = new QLineEdit(centralWidget);
        speedLineEdit->setObjectName("speedLineEdit");
        speedLineEdit->setPlaceholderText("Введите скорость (м/с)");

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setText("Рассчитать");

        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setText("Результат будет показан здесь");
        layout = new QVBoxLayout(centralWidget);
        layout->addWidget(minutesLineEdit);
        layout->addWidget(secondsLineEdit);
        layout->addWidget(speedLineEdit);
        layout->addWidget(pushButton);
        layout->addWidget(resultLabel);

        cursovaya->setCentralWidget(centralWidget); 
    }

    void retranslateUi(QMainWindow* cursovaya)
    {
        cursovaya->setWindowTitle(QCoreApplication::translate("cursovaya", "cursovaya", nullptr));
    }
};

namespace Ui {
    class cursovaya : public Ui_cursovaya {};
}

QT_END_NAMESPACE

#endif 
