#ifndef TRIANGLE_PRISM_WINDOW_H
#define TRIANGLE_PRISM_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TrianglePrismWindow; }
QT_END_NAMESPACE

class TrianglePrismWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrianglePrismWindow(QWidget* parent = nullptr);
    ~TrianglePrismWindow();

private slots:
    void onCalculateAreaAndVolume(); 

private:
    Ui::TrianglePrismWindow* ui;
};

#endif
