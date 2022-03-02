#ifndef FILETYPESSTRATEGY_H
#define FILETYPESSTRATEGY_H
#include "CalculateStrategy.h"

class FileTypesStrategy : public ICalculateStrategy
{
public:
    FileTypesStrategy() = default;
    void Calculate(const QString &path) override;
    virtual ~FileTypesStrategy() {}
};

#endif // FILETYPESSTRATEGY_H
