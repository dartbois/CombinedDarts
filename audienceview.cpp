#include "audienceview.h"
#include "ui_audienceview.h"
#include "scorerview.h"


AudienceView::AudienceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudienceView)
{
    ui->setupUi(this);
    this->setWindowTitle("Audience View");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);


    QString Stats = "                                 ";
    StatisticsDisplay = ui->StatisticsDisplay;
    Player2Stats = ui->Player2Stats;
    BothP1AndP2Stats = ui->BothP1AndP2Stats;
    CurrentPlayer = ui->CurrentPlayer;
    NumberOf180s = ui->NumberOf180s;
    WinPercentages = ui->WinPercentages;
    PersonalStats = ui->PersonalStats;
    MatchStats = ui->MatchStats;
    RankedStats = ui->RankedStats;

}

AudienceView::~AudienceView()
{
    delete ui;
}

void AudienceView::on_StatisticsDisplay_linkActivated(const QString &link)
{

}

void AudienceView::on_Player2Stats_linkActivated(const QString &link)
{

}

void AudienceView::on_BothP1AndP2Stats_linkActivated(const QString &link)
{

}

void AudienceView::on_CurrentPlayer_linkActivated(const QString &link)
{

}

void AudienceView::on_NumberOf180s_linkActivated(const QString &link)
{

}

void AudienceView::on_WinPercentages_linkActivated(const QString &link)
{

}

void AudienceView::on_PersonalStats_linkActivated(const QString &link)
{

}

void AudienceView::on_MatchStats_linkActivated(const QString &link)
{

}

void AudienceView::on_RankedStats_linkActivated(const QString &link)
{

}

void AudienceView::setPlayerOneStatsText()
{
    ui->StatisticsDisplay->setText("Player One Statistics : ");
}

void AudienceView::setPlayerTwoStatsText()
{
    ui->Player2Stats->setText("Player Two Statistics : ");
}

void AudienceView::setBothP1AndP2StatsText()
{
    ui->BothP1AndP2Stats->setText("Player One and Player Two Statistics : ");
}

void AudienceView::setCurrentPlayerText()
{
    ui->CurrentPlayer->setText("Current Player Statistics : ");
}

void AudienceView::setNumberOf180sText()
{
    ui->NumberOf180s->setText("Number of 180s : ");
}

void AudienceView::setWinPercentagesText()
{
    ui->WinPercentages->setText("Win Percentages : ");
}

void AudienceView::setPersonalStatsText()
{
    ui->PersonalStats->setText("Personal Statistics : ");
}

void AudienceView::setMatchStatsText()
{
    ui->MatchStats->setText("Match Statistics : ");
}

void AudienceView::setRankedStatsText()
{
    ui->RankedStats->setText("Ranked Statistics : ");
}

void AudienceView::undoRankedText()         //Experimental
{
    ui->RankedStats->clear();
}

void AudienceView::undoMatchStatsText()
{
    ui->MatchStats->clear();
}

void AudienceView::undoPlayerTwoStatsText()
{
    ui->Player2Stats->clear();
}

void AudienceView::undoBothP1AndP2StatsText()
{
    ui->BothP1AndP2Stats->clear();
}
void AudienceView::undoCurrentPlayerText()
{
    ui->CurrentPlayer->clear();
}

void AudienceView::undoNumberOf180sText()
{
    ui->NumberOf180s->clear();
}

void AudienceView::undoWinPercentagesText()
{
    ui->WinPercentages->clear();
}

void AudienceView::undoPersonalStatsText()
{
    ui->PersonalStats->clear();
}

void AudienceView::undoPlayerOneStatsText()
{
    ui->StatisticsDisplay->clear();
}
