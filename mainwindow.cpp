#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second.h"

#include <stdio.h>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(Repository &repo,QWidget *parent) :
    r(repo), QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Presenter");
    try
    {
        this->r.loadFromFileQ();
        this->r.loadFromFileP();
    }
    catch(Exception &e)
    {
            cout<<e.what()<<endl;
    }
    this->populateTableQ();

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addQ()));


}

void MainWindow::addQ()
{
    QString idlabel = ui->lineEditID->text();
    QString textlabel = ui->lineEditText->text();
    QString calabel = ui->lineEditCA->text();
    QString scorelabel = ui->lineEditScore->text();


    int id = idlabel.toInt();
    string text = textlabel.toStdString();
    string answer = calabel.toStdString();
    int score = scorelabel.toInt();

    try
    {
        this->r.addQuestion(id, text, answer, score);
        this->populateTableQ();
    }
    catch(Exception& e)
    {
        QMessageBox::critical(this, "Eroare", "Salvarea nu s-a putut executa: "+ QString::fromStdString(e.what()));
    }
}

void MainWindow::populateTableQ()
{
    int index = 0;
    ui->tableQuestions->setRowCount(this->r.getQuestions().size());

    this->r.sortQById();

    for(Question& q : this->r.getQuestions())
    {
        ui->tableQuestions->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(to_string(q.getId()))));
        ui->tableQuestions->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(q.getText())));
        ui->tableQuestions->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(q.getCorrectAnswer())));
        ui->tableQuestions->setItem(index, 3, new QTableWidgetItem(QString::fromStdString(to_string(q.getScore()))));

        index++;
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}
