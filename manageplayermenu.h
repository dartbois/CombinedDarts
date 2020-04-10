#ifndef MANAGEPLAYERMENU_H
#define MANAGEPLAYERMENU_H

#include <QtWidgets/QDialog>

namespace Ui {
class ManagePlayerMenu;
}

class ManagePlayerMenu : public QDialog
{
    Q_OBJECT

public:
    void FillPlayerList();
    explicit ManagePlayerMenu(QWidget *parent = nullptr);
    ~ManagePlayerMenu();

private slots:
    void on_PlayerMenuRemove_clicked();

    void on_PlayerMenuAdd_clicked();

private:
    Ui::ManagePlayerMenu *ui;


};

#endif // MANAGEPLAYERMENU_H
