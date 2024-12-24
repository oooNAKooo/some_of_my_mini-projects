#ifndef KALORII_H
#define KALORII_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class kalorii; }
QT_END_NAMESPACE

class kalorii : public QMainWindow
{
    Q_OBJECT

public:
    explicit kalorii(QWidget* parent = nullptr);
    ~kalorii();

private slots:
    void onCalculateCalories();  

private:
    Ui::kalorii* ui;
};

#endif 
