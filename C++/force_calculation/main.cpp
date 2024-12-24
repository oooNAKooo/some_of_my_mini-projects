#include "motion_app.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MotionApp w;
    w.show();
    return a.exec();
}
