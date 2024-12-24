#ifndef UI_TRIANGLE_PRISM_WINDOW_H
#define UI_TRIANGLE_PRISM_WINDOW_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrianglePrismWindow
{
public:
    QWidget* centralWidget;
    QLineEdit* side1LineEdit;  
    QLineEdit* side2LineEdit; 
    QLineEdit* heightLineEdit;
    QPushButton* calculateButton; 
    QLabel* resultLabel;        
    QVBoxLayout* layout;

    void setupUi(QMainWindow* TrianglePrismWindow)
    {
        if (TrianglePrismWindow->objectName().isEmpty())
            TrianglePrismWindow->setObjectName("TrianglePrismWindow");
        TrianglePrismWindow->resize(400, 300);

        centralWidget = new QWidget(TrianglePrismWindow);
        centralWidget->setObjectName("centralWidget");

        side1LineEdit = new QLineEdit(centralWidget);
        side1LineEdit->setObjectName("side1LineEdit");
        side1LineEdit->setPlaceholderText("Первый катет (m)");

        side2LineEdit = new QLineEdit(centralWidget);
        side2LineEdit->setObjectName("side2LineEdit");
        side2LineEdit->setPlaceholderText("Второй катет (m)");

        heightLineEdit = new QLineEdit(centralWidget);
        heightLineEdit->setObjectName("heightLineEdit");
        heightLineEdit->setPlaceholderText("Высота призмы (m)");

        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName("calculateButton");
        calculateButton->setText("Вычислить");

        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setText("Ответ после вычислений");

        layout = new QVBoxLayout(centralWidget);
        layout->addWidget(side1LineEdit);
        layout->addWidget(side2LineEdit);
        layout->addWidget(heightLineEdit);
        layout->addWidget(calculateButton);
        layout->addWidget(resultLabel);

        TrianglePrismWindow->setCentralWidget(centralWidget);
    }

    void retranslateUi(QMainWindow* TrianglePrismWindow)
    {
        TrianglePrismWindow->setWindowTitle(QCoreApplication::translate("TrianglePrismWindow", "Triangle Prism Calculator", nullptr));
    }
};

namespace Ui {
    class TrianglePrismWindow : public Ui_TrianglePrismWindow {};
}

QT_END_NAMESPACE

#endif 
