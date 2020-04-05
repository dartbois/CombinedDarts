#ifndef SCORERVIEW_H
#define SCORERVIEW_H

#include <QDialog>

namespace Ui {
class ScorerView;
}

class ScorerView : public QDialog
{
    Q_OBJECT

public:
    explicit ScorerView(QWidget *parent = nullptr);
    ~ScorerView();

private:
    Ui::ScorerView *ui;
};

#endif // SCORERVIEW_H
