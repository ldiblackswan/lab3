#include <QApplication>
#include "ExplorerForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExplorerForm exp;
    exp.show();
    return a.exec();
}
