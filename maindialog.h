#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QtSql>


namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();


private slots:


    void on_pushButtonCreateDB_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonAddTable_clicked();

    void on_pushButtonAddCustomer_clicked();

private:
    Ui::MainDialog *ui;

};

#endif // MAINDIALOG_H
