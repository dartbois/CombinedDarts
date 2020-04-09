#include "gameselectionmenu.h"
#include "ui_gameselectionmenu.h"


GameSelectionMenu::GameSelectionMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameSelectionMenu)
{
    ui->setupUi(this);
    audienceWindow = new AudienceView();
    scorerWindow = new ScorerView(audienceWindow);
}

GameSelectionMenu::~GameSelectionMenu()
{
    delete ui;
}

void GameSelectionMenu::on_pushButton_clicked()
{
    scorerWindow->show();
    audienceWindow->show();
    this->hide();
}
