#ifndef CALCULATESTRATEGY_H
#define CALCULATESTRATEGY_H
#include <QString>

class ICalculateStrategy
{
public:
    virtual void Calculate(const QString& path) = 0;
    virtual ~ICalculateStrategy() {}
};

class CalculateStrategy
{
public:
    explicit CalculateStrategy(ICalculateStrategy* strategy) : strat(strategy) {}
    void Calculate(const QString& path)
    {
        strat->Calculate(path);
    }
    void setStrategy(ICalculateStrategy* calculate_strategy)
    {
        strat = calculate_strategy;
    }
private:
    ICalculateStrategy *strat;
};

#endif // CALCULATESTRATEGY_H
