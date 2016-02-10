#ifndef BAZA_H
#define BAZA_H

#include <QMainWindow>

namespace Ui {
class Baza;
}

class Baza : public QMainWindow
{
    Q_OBJECT

public:
    explicit Baza(QWidget *parent = 0);
    void Zapisz(QString = "");
    ~Baza();

private slots:
    void on_wczytaj_clicked();
    void on_zapisz_clicked();
    void on_back_clicked();

private:
    Ui::Baza *ui;
};

#endif // BAZA_H
