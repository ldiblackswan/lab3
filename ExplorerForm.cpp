#include "ExplorerForm.h"
#include "ui_explorer.h"


ExplorerForm::ExplorerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Explorer)
{
    ui->setupUi(this);
}

ExplorerForm::~ExplorerForm() {}
