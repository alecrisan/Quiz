#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Repository.h"
#include "second.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Repository &repo, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Repository &r;

private slots:
    void populateTableQ();
    void addQ();
};

#endif // MAINWINDOW_H
