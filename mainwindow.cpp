#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "baza.h"
#include "ui_baza.h"
#include <QApplication>
#include <QString>
#include "QFileDialog"
#include <QTextStream>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int ile_PC = 0;
QString poprzedniaSciezka;

class Komputer {

    public:

        QString klasa;
        QString Dysk;
        QString Procesor;
        QString stan;
        QString cena;
        QString kod;
        void Dodaj_PC();
};

Komputer komputer[1000];

void MainWindow::Wczytaj()
{

        QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/Pulpit/", tr("Pliki txt (*.txt)"));
        if(fileName.isEmpty())
            return;
        QFile plik(fileName);
        if(!plik.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

                QTextStream in(&plik);
                int i=0;
                while (!in.atEnd()) {
                    QString line = in.readLine();


               for(int l=0; l<6;l++)
                    if(l==0)
                    {
                    komputer[i].klasa = line;
                    }
               else
                    if(l==1)
                    {
                    komputer[i].Procesor = line;
                    }
                else
                    if(l==2)
                    {
                    komputer[i].Dysk = line;
                    }
               else
                    if(l==3)
                    {
                    komputer[i].stan = line;
                    }
               else
                    if(l==4)
                    {
                    komputer[i].cena = line;
                    }
               else
                    if(l==5)
                    {
                    komputer[i].kod = line;
                    }
                    i++;
                }
                    poprzedniaSciezka = fileName;
                    plik.close();
};


void MainWindow::on_Nowa_clicked()
{
    //Baza * nowa;
    //nowa = new Baza;
   // nowa->show();
}
