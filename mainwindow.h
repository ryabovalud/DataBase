#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Add_Disc_clicked();

    void on_Del_Disc_clicked();

    void on_OK_Disc_clicked();

    void on_Cancle_Disc_clicked();

    void on_Add_cDisc_clicked();

    void on_Del_cDisc_clicked();

    void on_OK_cDisc_clicked();

    void on_Cancle_cDisc_clicked();

    void on_Add_Spec_clicked();

    void on_Del_Spec_clicked();

    void on_OK_Spec_clicked();

    void on_Cancle_Spec_clicked();

    void on_Add_Kaf_clicked();

    void on_Del_Kaf_clicked();

    void on_OK_Kaf_clicked();

    void on_Cancle_Kaf_clicked();

    void on_Add_Disc_CDisc_clicked();

    void on_Del_Disc_CDisc_clicked();

    void on_OK_Disc_CDisc_clicked();

    void on_Cancle_Disc_CDisc_clicked();

    void on_Add_All_Kod_clicked();

    void on_Del_All_Kod_clicked();

    void on_OK_All_Kod_clicked();

    void on_Cancle_All_Kod_clicked();



    void on_pbGenerateReport_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *All_Kod, *Disc, *Disc_CDisc, *Kaf, *Spec, *cDisc;
    QSqlQueryModel *Disc_SUB, *Kaf_SUB, *Spec_SUB, *cDisc_SUB;
    void UpdateDB();

};

#endif // MAINWINDOW_H
