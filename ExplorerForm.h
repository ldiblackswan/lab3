#ifndef EXPLORERFORM_H
#define EXPLORERFORM_H
#include "FileTableModel.h"
#include <QWidget>
#include <QItemSelection>
#include <QFileSystemModel>
#include "CalculateStrategy.h"

namespace Ui {
    class Explorer;
}


class ExplorerForm : public QWidget
{
    Q_OBJECT
public:
    enum class GroupedBy {
        Folders,
        Types
    };
    void updateModelData();
    explicit ExplorerForm(QWidget *parent = nullptr);
    ~ExplorerForm();
protected slots:
    void changeGrouping(int index);
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
private:
    Ui::Explorer* ui;
    QFileSystemModel* tree_model;
    FileTableModel* table_model;
    QList<Data> data;
    CalculateStrategy* context;
    QString folder_path;
    GroupedBy grouping;
};


#endif // EXPLORERFORM_H

