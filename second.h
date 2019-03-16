#ifndef SECOND_H
#define SECOND_H

#include <QWidget>
#include "observer.h"
#include "Participant.h"
#include "Repository.h"
#include "QTableWidgetItem"

namespace Ui {
class Second;
}

class Second : public QWidget, public Observer
{
    Q_OBJECT

public:
    Participant &participant;
    Repository &repo;

    Second(Participant &p,Repository &r,QWidget *parent = 0);

    void update() override;

    ~Second();

private:
    Ui::Second *ui;

private slots:

    void populateTableP();
    void answerQ();

    void on_tableQ_cellClicked(int row, int column);
    void on_tableQ_itemClicked(QTableWidgetItem *item);
    void verify(int row, int col);
};

#endif // SECOND_H
