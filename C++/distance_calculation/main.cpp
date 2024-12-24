#include "cursovaya.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    cursovaya w;
    w.show();
    return a.exec();
}
