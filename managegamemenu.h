#ifndef MANAGEGAMEMENU_H
#define MANAGEGAMEMENU_H

#include <QtWidgets/QDialog>

namespace Ui {
class ManageGameMenu;
}

class ManageGameMenu : public QDialog
{
    Q_OBJECT

public:
    void FillGameList();
    explicit ManageGameMenu(QWidget *parent = nullptr);
    ~ManageGameMenu();

private:
    Ui::ManageGameMenu *ui;
};

#endif // MANAGEGAMEMENU_H
