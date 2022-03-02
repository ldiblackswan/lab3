#include <QCoreApplication>
#include "CalculateStrategy.h"
#include "FileTypesStrategy.h"
#include "FoldersStrategy.h"

int main(int argc, char *argv[])
{
    ICalculateStrategy* calc_strat = new FoldersStrategy();
    CalculateStrategy* calc = new CalculateStrategy(calc_strat);
    calc->Calculate("D:/Temp");
    delete calc;
    delete calc_strat;
    return 0;
}
