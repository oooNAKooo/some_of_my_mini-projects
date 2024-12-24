#ifndef UI_MOTION_APP_H
#define UI_MOTION_APP_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MotionApp
{
public:
    QWidget* centralWidget;
    QLineEdit* speedLineEdit;    
    QLineEdit* timeLineEdit;     
    QLineEdit* forceLineEdit;    
    QPushButton* pushButton;    
    QLabel* resultLabel;        
    QVBoxLayout* layout;

    void setupUi(QMainWindow* MotionApp)
    {
        if (MotionApp->objectName().isEmpty())
            MotionApp->setObjectName("MotionApp");
        MotionApp->resize(400, 300);

        centralWidget = new QWidget(MotionApp);
        centralWidget->setObjectName("centralWidget");

        speedLineEdit = new QLineEdit(centralWidget);
        speedLineEdit->setObjectName("speedLineEdit");
        speedLineEdit->setPlaceholderText("Скорость (m/s)");

        timeLineEdit = new QLineEdit(centralWidget);
        timeLineEdit->setObjectName("timeLineEdit");
        timeLineEdit->setPlaceholderText("Время (m)");

        forceLineEdit = new QLineEdit(centralWidget);
        forceLineEdit->setObjectName("forceLineEdit");
        forceLineEdit->setPlaceholderText("Сила (N)");

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setText("Вычислить");

        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setText("Здесь будет результат");

        layout = new QVBoxLayout(centralWidget);
        layout->addWidget(speedLineEdit);
        layout->addWidget(timeLineEdit);
        layout->addWidget(forceLineEdit);
        layout->addWidget(pushButton);
        layout->addWidget(resultLabel);

        MotionApp->setCentralWidget(centralWidget);
    }

    void retranslateUi(QMainWindow* MotionApp)
    {
        MotionApp->setWindowTitle(QCoreApplication::translate("MotionApp", "MotionApp", nullptr));
    }
};

namespace Ui {
    class MotionApp : public Ui_MotionApp {};
}

QT_END_NAMESPACE

#endif
