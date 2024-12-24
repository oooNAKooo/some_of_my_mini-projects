#ifndef cursovaya_H
#define cursovaya_H

#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class cursovaya; }
QT_END_NAMESPACE

class cursovaya : public QMainWindow
{
    Q_OBJECT

public:
    explicit cursovaya(QWidget* parent = nullptr);
    ~cursovaya();

private slots:
    void onCalculateDistance();

private:
    Ui::cursovaya* ui;
};

#endif
