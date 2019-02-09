#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    QByteArray a;
    a.append((char)ui->spinBox->value());
    a.append((char)ui->spinBox_2->value());
    int n = a[0]+a[1];
    ui->label_2->setText(QString::number(n));
}
