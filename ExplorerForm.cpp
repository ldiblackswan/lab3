#include "ExplorerForm.h"
#include "ui_explorer.h"
#include "FoldersStrategy.h"
#include "FileTypesStrategy.h"

ExplorerForm::ExplorerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Explorer)
{
    ui->setupUi(this);
    tree_model = new QFileSystemModel(this);
    table_model = new FileTableModel;
    context = new CalculateStrategy;
    tree_model->setRootPath(QDir::currentPath());
    tree_model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden);
    ui->treeView->setModel(tree_model);
    ui->tableView->setModel(table_model);
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    grouping = GroupedBy::Folders;

    connect(ui->groupBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ExplorerForm::changeGrouping);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this,  &ExplorerForm::selectionChanged);
}


void ExplorerForm::updateModelData()
{
    if (folder_path.isEmpty())
        return;
    switch (grouping) {
    case GroupedBy::Folders:
        context->setStrategy(new FoldersStrategy);
        break;
    case GroupedBy::Types:
        context->setStrategy(new FileTypesStrategy);
        break;
    }
    data = context->Calculate(folder_path);
    table_model->setModelData(data);
}

void ExplorerForm::changeGrouping(int index)
{
    switch (index) {
        case 0:
            grouping = GroupedBy::Folders;
            break;
        case 1:
            grouping = GroupedBy::Types;
            break;
        default:
            grouping = GroupedBy::Folders;
            break;
    }
    updateModelData();
}


void ExplorerForm::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList indexes = selected.indexes();
    folder_path = tree_model->filePath(indexes[0]);
    updateModelData();
}

ExplorerForm::~ExplorerForm()
{
    delete ui;
    delete tree_model;
    delete table_model;
    delete context;
}

