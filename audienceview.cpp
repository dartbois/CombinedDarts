#include "audienceview.h"
#include "ui_audienceview.h"

AudienceView::AudienceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudienceView)
{
    ui->setupUi(this);
    this->setWindowTitle("Audience View");
}

AudienceView::~AudienceView()
{
    delete ui;
}
