#include "manageplayermenu.h"
#include "ui_manageplayermenu.h"

ManagePlayerMenu::ManagePlayerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagePlayerMenu)
{
    ui->setupUi(this);
}

ManagePlayerMenu::~ManagePlayerMenu()
{
    delete ui;
}
