#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "baza.h"
#include "ui_baza.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     void Wczytaj();
     QStringList dane;
    ~MainWindow();

private slots:
    void on_Nowa_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
