#include "manageplayermenu.h"
#include "ui_manageplayermenu.h"
#include "datahandler.h"

ManagePlayerMenu::ManagePlayerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagePlayerMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Manage Player Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    FillPlayerList();
    playerAddEditMenu = new PlayerAddEditMenu();
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

    QString header = "Player ID\tFirst\tLast\tHometown\tLeague Rank\tGames Played";
    ui->listWidget->addItem(header);

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

void ManagePlayerMenu::on_PlayerMenuAdd_clicked()
{
     playerAddEditMenu -> show();
}

void ManagePlayerMenu::on_PlayerMenuEdit_clicked()
{
     playerAddEditMenu -> show();
}

void ManagePlayerMenu::on_PlayerMenuRemove_clicked()
{
    //Row 0 is the header and cannot be removed.
   if (ui->listWidget->currentRow() != 0){
       DataHandler myD;

       QString currentItem = ui->listWidget->currentItem()->text();
       QStringList currentItemList = currentItem.split("\t");
       currentItem = currentItemList[0];

       string currentItemID = currentItem.toStdString();

       string req = currentItemID + ":removePlayer";

       myD.sqlGet(req);

       FillPlayerList();
   }
}
