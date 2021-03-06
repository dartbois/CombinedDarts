#ifndef GAMESELECTIONMENU_H
#define GAMESELECTIONMENU_H

#include <QDialog>
#include "scorerview.h"
#include "audienceview.h"

namespace Ui {
class GameSelectionMenu;
}

class GameSelectionMenu : public QDialog
{
    Q_OBJECT

public:
    void FillGameList();
    explicit GameSelectionMenu(QWidget *parent = nullptr);
    ~GameSelectionMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameSelectionMenu *ui;
    AudienceView* audienceWindow;
    ScorerView* scorerWindow;
};

#endif // GAMESELECTIONMENU_H
