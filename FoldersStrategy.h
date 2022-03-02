#ifndef FOLDERSSTRATEGY_H
#define FOLDERSSTRATEGY_H
#include "CalculateStrategy.h"
#include <QPair>

class FoldersStrategy : public ICalculateStrategy
{
public:
    FoldersStrategy() = default;
    QList<Data> Calculate(const QString& path) override;
    virtual ~FoldersStrategy() {}
    void consoleOutput(const QList<QPair<QString, qint64> >& foldersAndSizes,
                       const QList<QPair<QString, double> >& foldersAndPercents) const;
protected:
    QList<QPair<QString, qint64> > FoldersAndSizes(const QString& path) const;
    QList<QPair<QString, double> > FoldersAndPercents(const QList<QPair<QString, qint64> >& foldersAndSizesList,
                                                      const qint64& totalSize) const;
};
#endif // FOLDERSSTRATEGY_H
