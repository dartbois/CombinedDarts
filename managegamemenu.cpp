#include "managegamemenu.h"
#include "ui_managegamemenu.h"

ManageGameMenu::ManageGameMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageGameMenu)
{
    ui->setupUi(this);

}

ManageGameMenu::~ManageGameMenu()
{
    delete ui;
}
