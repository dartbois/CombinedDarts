#ifndef AUDIENCEVIEW_H
#define AUDIENCEVIEW_H

#include <QDialog>

namespace Ui {
class AudienceView;
}

class AudienceView : public QDialog
{
    Q_OBJECT

public:
    explicit AudienceView(QWidget *parent = nullptr);
    ~AudienceView();

private:
    Ui::AudienceView *ui;
};

#endif // AUDIENCEVIEW_H
