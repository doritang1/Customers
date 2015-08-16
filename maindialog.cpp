#include "maindialog.h"
#include "ui_maindialog.h"
#include "initdb.h"

#include <QtSql>
#include <QDebug>
#include <QFileDialog>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    initDb("C:/CyberK/QtProjects/Customers/");

    QSqlQueryModel *customerModel = new QSqlQueryModel(this);
    customerModel->setQuery("select * from customerInfo");
    ui->tableViewCustomer->setModel(customerModel);
    ui->tableViewCustomer->show();
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_pushButtonCreateDB_clicked()
{
    QDir dbDir = QFileDialog::getExistingDirectory(this,"choose a directory", "");

    initDb(dbDir.path()+"/");
}

void MainDialog::on_pushButtonAdd_clicked()
{

}

void MainDialog::on_pushButtonAddTable_clicked()
{
    createTables();
}

void MainDialog::on_pushButtonAddCustomer_clicked()
{
    addCustomer(ui->lineEditCustomerId->text(),
                ui->lineEditEnterpriseName->text(),
                ui->lineEditCeoName->text(),
                ui->textEditEtc->toPlainText());
}
