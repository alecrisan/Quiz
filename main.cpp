#include "mainwindow.h"
#include <QApplication>
#include "second.h"

int main(int argc, char *argv[])
{
    try
    {
    QApplication a(argc, argv);
    Repository r{};
    r.loadFromFileP();
    r.loadFromFileQ();
    MainWindow w{r};
    w.show();

    Second s1{r.getParticipants().at(0), r};
    s1.setWindowTitle(QString::fromStdString(r.getParticipants().at(0).getName()));
    s1.show();

    Second s2{r.getParticipants().at(1), r};
    s2.setWindowTitle(QString::fromStdString(r.getParticipants().at(1).getName()));
    s2.show();

    Second s3{r.getParticipants().at(2), r};
    s3.setWindowTitle(QString::fromStdString(r.getParticipants().at(2).getName()));
    s3.show();

    Second s4{r.getParticipants().at(3), r};
    s4.setWindowTitle(QString::fromStdString(r.getParticipants().at(3).getName()));
    s4.show();

    Second s5{r.getParticipants().at(4), r};
    s5.setWindowTitle(QString::fromStdString(r.getParticipants().at(4).getName()));
    s5.show();


    return a.exec();
    }
    catch(Exception & e)
    {
            cout<<e.what();
    }
}
