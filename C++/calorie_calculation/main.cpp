#include "kalorii.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    kalorii w;
    w.show();
    return a.exec();
}
