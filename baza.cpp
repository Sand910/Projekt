#include "baza.h"
#include "ui_baza.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <QTextStream>
#include <QDebug>
#include <QFile>




QString tekst;
QString poprzedniaSciezka1;

Baza::Baza(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Baza)
{
    ui->setupUi(this);
}

Baza::~Baza()
{
    delete ui;
}



void Baza::Zapisz(QString fileName)
{
    tekst = ui->poleTekstowe->toPlainText();

    if(fileName.isEmpty())
        fileName = QFileDialog::getSaveFileName
                (this,tr("Zapisz plik jako..."),tr("/home/"),tr("Pliki tekstowe (*.txt)"));

    if(fileName.isEmpty())
        return;

    QFile plik(fileName);
    plik.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    QTextStream stream(&plik);
    stream << tekst;

    poprzedniaSciezka1 = fileName;

    plik.close();
}



void Baza::on_wczytaj_clicked()
{
    //Wczytaj();
}

void Baza::on_zapisz_clicked()
{
    Zapisz();
}

void Baza::on_back_clicked()
{
    close();
}

