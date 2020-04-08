#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <QtWidgets/QWidget>
#include <QtCharts/QPieSeries>
#include <QLabel>

QT_CHARTS_USE_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    int score = 0;
public slots:
    void addScore();

private:
    QList<QPieSeries *> m_donuts;

    QLabel *scoreDisplayer;
};

#endif // WIDGET_H
