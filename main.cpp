#include "frientlist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frientList* w =new frientList();
    w->show();
    return a.exec();
}
