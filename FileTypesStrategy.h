#ifndef FILETYPESSTRATEGY_H
#define FILETYPESSTRATEGY_H
#include "CalculateStrategy.h"

class FileTypesStrategy : public ICalculateStrategy
{
public:
    FileTypesStrategy() = default;
    QList<Data> Calculate(const QString &path) override;
    virtual ~FileTypesStrategy() {}
    void consoleOutput(const QList<QPair<QString, qint64> >& typesAndSizes,
                       const QList<QPair<QString, double> >& typesAndPercents) const;
protected:
    void TypesAndSizes(const QString& path, QList<QPair<QString, qint64> >& typesAndSizes) const;
};

#endif // FILETYPESSTRATEGY_H
