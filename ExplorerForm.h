#ifndef EXPLORERFORM_H
#define EXPLORERFORM_H

#include <QWidget>
#include <QItemSelection>

namespace Ui {
    class Explorer;
}


class ExplorerForm : public QWidget
{
    Q_OBJECT
public:
    explicit ExplorerForm(QWidget *parent = nullptr);
    ~ExplorerForm();
private:
    Ui::Explorer* ui;
};


#endif // EXPLORERFORM_Hf // EXPLORER_H

