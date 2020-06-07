#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <LimeReport>

void MainWindow::UpdateDB(){

    Disc_SUB->setQuery("select * from Disc");
    Kaf_SUB->setQuery("select * from Kaf");
    Spec_SUB->setQuery("select * from Spec");
    cDisc_SUB->setQuery("select * from cDisc");

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Disc_SUB = new QSqlQueryModel;
    cDisc_SUB = new QSqlQueryModel;
    Kaf_SUB = new QSqlQueryModel;
    Spec_SUB = new QSqlQueryModel;

    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/brrri/OneDrive/Study/BD/BD.txt");
        if (!db.open())
          {
           qDebug() << "Cannot open database:" << db.lastError();
          }
        db.open();
        db.exec("pragma foreign_keys=on");

        //Ïîäêëþ÷àåì òàáëèöû ê ýëåìåíòàì
        // ÏÎÄËÅÆÀÙÈÅ ÈÇÌÅÍÅÈÞ
        //Disc
        ui->Disc->setWindowTitle("Disc");
        ui->Disc->show();
        Disc = new QSqlTableModel(0,db);
        Disc->setTable("Disc");
        Disc->select();
        ui->Disc->setModel(Disc);
        Disc->setEditStrategy(QSqlTableModel::OnManualSubmit);

        ui->Disc_2->setWindowTitle("Disc");
        ui->Disc_2->show();
        ui->Disc_2->setModel(Disc);

        ui->Disc_3->setWindowTitle("Disc");
        ui->Disc_3->show();
        ui->Disc_3->setModel(Disc);

        //cDisc
        ui->cDisc->setWindowTitle("cDisc");
        ui->cDisc->show();
        cDisc = new QSqlTableModel(0,db);
        cDisc->setTable("cDisc");
        cDisc->select();
        ui->cDisc->setModel(cDisc);
        cDisc->setEditStrategy(QSqlTableModel::OnManualSubmit);

        ui->cDisc_2->setWindowTitle("cDisc");
        ui->cDisc_2->show();
        ui->cDisc_2->setModel(cDisc);

        ui->cDisc_3->setWindowTitle("cDisc");
        ui->cDisc_3->show();
        ui->cDisc_3->setModel(cDisc);

        //Spec
        ui->Spec->setWindowTitle("Spec");
        ui->Spec->show();
        Spec = new QSqlTableModel(0,db);
        Spec->setTable("Spec");
        Spec->select();
        ui->Spec->setModel(Spec);
        Spec->setEditStrategy(QSqlTableModel::OnManualSubmit);

        //Kaf
        ui->Kaf->setWindowTitle("Kaf");
        ui->Kaf->show();
        Kaf = new QSqlTableModel(0,db);
        Kaf->setTable("Kaf");
        Kaf->select();
        ui->Kaf->setModel(Kaf);
        Kaf->setEditStrategy(QSqlTableModel::OnManualSubmit);

        ui->Kaf_2->setWindowTitle("Kaf");
        ui->Kaf_2->show();
        ui->Kaf_2->setModel(Kaf);

        //Disc_CDisc
        ui->Disc_CDisc->setWindowTitle("Disc_CDisc");
        ui->Disc_CDisc->show();
        Disc_CDisc = new QSqlTableModel(0,db);
        Disc_CDisc->setTable("Disc_CDisc");
        Disc_CDisc->select();
        ui->Disc_CDisc->setModel(Disc_CDisc);
        Disc_CDisc->setEditStrategy(QSqlTableModel::OnManualSubmit);

        //All
        ui->All_Kod->setWindowTitle("All_Kod");
        ui->All_Kod->show();
        All_Kod = new QSqlTableModel(0,db);
        All_Kod->setTable("All_Kod");
        All_Kod->select();
        ui->All_Kod->setModel(All_Kod);
        All_Kod->setEditStrategy(QSqlTableModel::OnManualSubmit);

        UpdateDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*****************************Disc***************************/
void MainWindow::on_Add_Disc_clicked()
{
    QSqlRecord rec;
    Disc->insertRecord(-1,rec);
}



void MainWindow::on_Del_Disc_clicked()
{

    int _Row;
            if (ui->Disc->selectionModel()->currentIndex().isValid())
            {
                _Row=ui->Disc->selectionModel()->currentIndex().row();
                Disc->removeRow(_Row);
            }

}

void MainWindow::on_OK_Disc_clicked()
{
    if  (!Disc->submitAll())
           {
            QMessageBox::information(this, tr("Error"),
                                     Disc->lastError().databaseText ());
    }

    else UpdateDB();

}

void MainWindow::on_Cancle_Disc_clicked()
{
    Disc->revertAll();
}

/*****************************cDisc***************************/
void MainWindow::on_Add_cDisc_clicked()
{
    QSqlRecord rec;
    cDisc->insertRecord(-1,rec);
}

void MainWindow::on_Del_cDisc_clicked()
{

    int _Row;
            if (ui->cDisc->selectionModel()->currentIndex().isValid())
            {
                _Row=ui->cDisc->selectionModel()->currentIndex().row();
                cDisc->removeRow(_Row);
            }

}

void MainWindow::on_OK_cDisc_clicked()
{
    if  (!cDisc->submitAll())
           {
            QMessageBox::information(this, tr("Error"),
                                     cDisc->lastError().databaseText ());

            }
   else UpdateDB();

}

void MainWindow::on_Cancle_cDisc_clicked()
{
    Disc->revertAll();
}

/*****************************Spec***************************/
void MainWindow::on_Add_Spec_clicked()
{
    QSqlRecord rec;
    Spec->insertRecord(-1,rec);
}

void MainWindow::on_Del_Spec_clicked()
{
           int _Row;
                if (ui->Spec->selectionModel()->currentIndex().isValid())
                {
                    _Row=ui->Spec->selectionModel()->currentIndex().row();
                    Spec->removeRow(_Row);
                }
}

void MainWindow::on_OK_Spec_clicked()
{
    if  (!Spec->submitAll())
           {
            QMessageBox::information(this, tr("Error"),
                                     Spec->lastError().databaseText ());

            }

    else UpdateDB();
}


void MainWindow::on_Cancle_Spec_clicked()
{
    Spec->revertAll();
}

/*****************************Kaf***************************/

void MainWindow::on_Add_Kaf_clicked()
{
    QSqlRecord rec;
    Kaf->insertRecord(-1,rec);
}

void MainWindow::on_Del_Kaf_clicked()
{
        int _Row;
                if (ui->Kaf->selectionModel()->currentIndex().isValid())
                {
                    _Row=ui->Kaf->selectionModel()->currentIndex().row();
                    Kaf->removeRow(_Row);
                }

}

void MainWindow::on_OK_Kaf_clicked()
{
    if  (!Kaf->submitAll())
           {
            QMessageBox::information(this, tr("Error"),
                                     Kaf->lastError().databaseText ());

            }

    else UpdateDB();
}

void MainWindow::on_Cancle_Kaf_clicked()
{
    Kaf->revertAll();
}
/*****************************Disc_CDisc***************************/
void MainWindow::on_Add_Disc_CDisc_clicked()
{
    QSqlRecord rec;
    Disc_CDisc->insertRecord(-1,rec);
}

void MainWindow::on_Del_Disc_CDisc_clicked()
{
        int _Row;
                if (ui->Disc_CDisc->selectionModel()->currentIndex().isValid())
                {
                    _Row=ui->Disc_CDisc->selectionModel()->currentIndex().row();
                    Disc_CDisc->removeRow(_Row);
                }
}

void MainWindow::on_OK_Disc_CDisc_clicked()
{
    if  (!Disc_CDisc->submitAll())
           {
            QMessageBox::information(this, tr("Error"),
                                     Disc_CDisc->lastError().databaseText ());

          }
}

void MainWindow::on_Cancle_Disc_CDisc_clicked()
{
    Disc_CDisc->revertAll();
}
/*****************************All_Kod***************************/
void MainWindow::on_Add_All_Kod_clicked()
{
    QSqlRecord rec;
    All_Kod->insertRecord(-1,rec);
}

void MainWindow::on_Del_All_Kod_clicked()
{

        int _Row;
                if (ui->All_Kod->selectionModel()->currentIndex().isValid())
                {
                    _Row=ui->All_Kod->selectionModel()->currentIndex().row();
                    All_Kod->removeRow(_Row);
                }
}

void MainWindow::on_OK_All_Kod_clicked()
{
    if  (!All_Kod->submitAll())
           {
            QMessageBox::information(this, tr("Error"),
                                     All_Kod->lastError().databaseText ());

            }
}

void MainWindow::on_Cancle_All_Kod_clicked()
{
    All_Kod->revertAll();
}

void MainWindow::on_pbGenerateReport_clicked()
{
    LimeReport::ReportEngine report;

        report.loadFromFile("C:/Users/brrri/OneDrive/Study/BD/DataBase/Report.lrxml");
        report.previewReport();

}
