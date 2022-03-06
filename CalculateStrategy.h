#ifndef CALCULATESTRATEGY_H
#define CALCULATESTRATEGY_H
#include <QString>
#include <QPair>
#include <QList>
#include "Data.h"

class ICalculateStrategy
{
public:
    virtual QList<Data> Calculate(const QString& path) = 0;
    virtual ~ICalculateStrategy() {}
protected:
    QList<Data> AllToData(const QList<QPair<QString, qint64> >&nameAndSizes,
                          const QList<QPair<QString, double> > &nameAndPercents) const;
    QList<QPair<QString, double> > namesAndPercents(const QList<QPair<QString, qint64> >& namesAndSizes,
                                                      const qint64& totalSize) const;
};

class CalculateStrategy
{
public:
    CalculateStrategy() = default;
    explicit CalculateStrategy(ICalculateStrategy* strategy) : strat(strategy) {}
    QList<Data> Calculate(const QString& path)
    {
        return strat->Calculate(path);
    }
    void setStrategy(ICalculateStrategy* calculate_strategy)
    {
        if (strat) {
            delete strat;
        }
        strat = calculate_strategy;
    }
    ~CalculateStrategy() {
        if (strat) {
            delete strat;
        }
    }
private:
    ICalculateStrategy *strat = nullptr;
};

#endif // CALCULATESTRATEGY_H
