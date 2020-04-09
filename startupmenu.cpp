#include "startupmenu.h"
#include "ui_startupmenu.h"

StartupMenu::StartupMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartupMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Startup Menu");
    manageChoiceMenu = new ManageChoiceMenu();
    dartboardWindow = new Widget();
    audienceWindow = new AudienceView();
    scorerWindow = new ScorerView(audienceWindow);

}

StartupMenu::~StartupMenu()
{
    delete ui;
}

void StartupMenu::on_pushButton_clicked()
{
    manageChoiceMenu->show();
}

void StartupMenu::changeWindow()
{
    if(manageChoiceMenu->isVisible())
    {
        manageChoiceMenu->hide();
        this->show();
    }
    else
    {
        this->hide();
        manageChoiceMenu->show();
    }
}

void StartupMenu::on_GameButton_clicked()
{
    scorerWindow->show();
    audienceWindow->show();
    dartboardWindow->setVisible(true);
    dartboardWindow->resize(400, 400);
    this->hide();
}
