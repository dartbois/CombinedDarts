#include "manageplayermenu.h"
#include "ui_manageplayermenu.h"
#include "datahandler.h"

ManagePlayerMenu::ManagePlayerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagePlayerMenu)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    FillPlayerList();
}

ManagePlayerMenu::~ManagePlayerMenu()
{
    delete ui;
}

void ManagePlayerMenu::FillPlayerList(){
    //Instance of datahandler
    DataHandler myD;

    //Begin by clearing the list
    ui->listWidget->clear();

    //Return a string of game info from sqlhandler. \n delimited.
    std::string playerInfo;
    playerInfo = myD.sqlGet("0:playerInfoList");
    QString QplayerInfo;
    QplayerInfo = QString::fromStdString(playerInfo);

    //Split the info by \n
    QStringList playerInfoList = QplayerInfo.split('\n');

    //Add list to listWidget
    ui->listWidget->addItems(playerInfoList);

}
