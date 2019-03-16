#include "second.h"
#include "ui_second.h"
#include "QMessageBox"

Second::Second(Participant& p,Repository &r,QWidget *parent) :
    participant(p), repo(r), QWidget(parent),
    ui(new Ui::Second)
{
    ui->setupUi(this);
    this->repo.addObserver(this);
    this->populateTableP();

    connect(ui->tableQ, SIGNAL(cellClicked(int,int)), this, SLOT(verify(int, int)));
    //connect(ui->tableQ, SIGNAL(cellClicked(int,int)), this, SLOT(on_tableQ_cellClicked(int,int)));
    connect(ui->answerButton, SIGNAL(clicked()), this, SLOT(answerQ()));
    //connect(ui->tableQ, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(on_tableQ_itemClicked(QTableWidgetItem*)));
}

void Second::update()
{
    this->populateTableP();
}

void Second::populateTableP()
{
    int index = 0;
    ui->tableQ->setRowCount(this->repo.getQuestions().size());

    this->repo.sortQByScore();

    for(Question& q : this->repo.getQuestions())
    {
        ui->tableQ->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(to_string(q.getId()))));
        ui->tableQ->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(q.getText())));
        ui->tableQ->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(to_string(q.getScore()))));

        index++;
     }

    ui->lineEditScore->setText("0");

}

void Second::answerQ()
{
    QString answer = ui->textEditAnswer->toPlainText();
    string ans = answer.toStdString();

    QList<QTableWidgetItem*> l = ui->tableQ->selectedItems();
    QTableWidgetItem* item = l.at(0);

    int row = item->row();
    int column = item->column();

    item = ui->tableQ->item(row, 0);

    QString s = item->text();
    string ss = s.toStdString();

    string correctanswer;
    int score;
    for(auto q: this->repo.getQuestions())
        if(q.getId() == stoi(ss))
        {
            correctanswer = q.getCorrectAnswer();
            score = q.getScore();
            break;
        }

    if(correctanswer != ans)
             QMessageBox::critical(this, "Eroare", "Raspuns gresit");

    if(correctanswer == ans && item->backgroundColor() != Qt::green)
    {
        ui->tableQ->item(row, 0)->setBackgroundColor(Qt::green);
        ui->tableQ->item(row, 1)->setBackgroundColor(Qt::green);
        ui->tableQ->item(row, 2)->setBackgroundColor(Qt::green);
        int old = stoi(ui->lineEditScore->text().toStdString());
        ui->lineEditScore->setText(QString::fromStdString(to_string(score + old)));
    }
    else if(item->backgroundColor() == Qt::green)
    {
         QMessageBox::critical(this, "Eroare", "Ati raspuns deja la intrebarea asta");
    }

}

void Second::verify(int row, int col)
{

    if (ui->tableQ->item(row, col)->backgroundColor() == Qt::green)
    {
        ui->answerButton->setDisabled(true);
        QMessageBox::critical(this, "Eroare", "Ati raspuns deja la intrebarea asta");
    }
    else
        ui->answerButton->setDisabled(false);
}

void Second::on_tableQ_cellClicked(int row, int column)
{


//    int r = this->answerQ();
//    if(r == row && r != -1)
//    {
//    QMessageBox::critical(this, "Eroare", "Salvarea nu s-a putut executa: ");
//    ui->tableQ->item(row, column)->setBackgroundColor(Qt::green);
//    ui->tableQ->item(row, column+1)->setBackgroundColor(Qt::green);
//    ui->tableQ->item(row, column+2)->setBackgroundColor(Qt::green);
//    }
    //this->answerQ();

}


void Second::on_tableQ_itemClicked(QTableWidgetItem *item)
{
    QString s = item->text();
    string ss = s.toStdString();

    string correctanswer;
    for(auto q: this->repo.getQuestions())
        if(q.getId() == stoi(ss))
        {
            correctanswer = q.getCorrectAnswer();
            break;
        }
    //ui->lineEdit2->setText(QString::fromStdString(correctanswer));


//    QString answer = ui->textEditAnswer->toPlainText();
//    string ans = answer.toStdString();

//    int row = item->row();
//    int column = item->column();
//    if(correctanswer == ans && ui->answerButton->isEnabled())
//    {
//        ui->tableQ->item(row, column)->setBackgroundColor(Qt::green);
//        ui->tableQ->item(row, column+1)->setBackgroundColor(Qt::green);
//        ui->tableQ->item(row, column+2)->setBackgroundColor(Qt::green);
//    }
//    else if(correctanswer != ans)
//        QMessageBox::critical(this, "Eroare", "Raspuns gresit");

}

Second::~Second()
{
    delete ui;
}
