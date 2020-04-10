#include "managegamemenu.h"
#include "ui_managegamemenu.h"
#include "datahandler.h"

ManageGameMenu::ManageGameMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageGameMenu)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    FillGameList();
}

ManageGameMenu::~ManageGameMenu()
{
    delete ui;
}

void ManageGameMenu::FillGameList(){
    //Instance of datahandler
    DataHandler myD;

    //Begin by clearing the list
    ui->listWidget->clear();

    //Return a string of game info from sqlhandler. \n delimited.
    std::string gameInfo;
    gameInfo = myD.sqlGet("1:gameInfoList");
    QString QgameInfo;
    QgameInfo = QString::fromStdString(gameInfo);

    //Split the info by \n
    QStringList gameInfoList = QgameInfo.split('\n');

    //Add list to listWidget
    ui->listWidget->addItems(gameInfoList);
}

void ManageGameMenu::on_GameMenuRemove_clicked()
{
    DataHandler myD;

    QString currentItem = ui->listWidget->currentItem()->text();
    QStringList currentItemList = currentItem.split("\t");
    currentItem = currentItemList[0];

    string currentItemID = currentItem.toStdString();

    string req = currentItemID + ":removeGame";

    myD.sqlGet(req);

    FillGameList();
}
