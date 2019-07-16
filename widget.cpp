#include "widget.h"
#include "ui_widget.h"
#include <qmessagebox.h>
#include <qstring.h>
//count coin
//show messagebox
//real reset money

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkmoney();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkmoney()
{
    if(this->money<200)
        ui->pbCoke->setDisabled(true);
    if(this->money<150)
        ui->pbTea->setDisabled(true);
    if(this->money<100)
        ui->pbCoffee->setDisabled(true);
    if(this->money>=200)
        ui->pbCoke->setDisabled(false);
    if(this->money>=150)
        ui->pbTea->setDisabled(false);
    if(this->money>=100)
        ui->pbCoffee->setDisabled(false);
}

int* Widget::resetMoney()
{
    int *array = new int[4]{0,};
    int coin[] = {500,100,50,10};
    for (int i = 0;i < 4;i++) {
        while(this->money-coin[i]>=0){
            *(array + i) += 1;
            this->money -= coin[i];
        }
    }
    return array;
}

void Widget::changemoney(int n)
{
    this->money += n;
    ui->LCD->display(this->money);
    checkmoney();
}
void Widget::on_pb10_clicked()
{
    changemoney(10);

}

void Widget::on_pb50_clicked()
{
    changemoney(50);
}

void Widget::on_pb100_clicked()
{
    changemoney(100);
}


void Widget::on_pb500_clicked()
{
    changemoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changemoney(-100);

}

void Widget::on_pbTea_clicked()
{
    changemoney(-150);

}

void Widget::on_pbCoke_clicked()
{
    changemoney(-200);

}

void Widget::on_Reset_clicked()
{
    int* p = resetMoney();
    QString str = QString();
    QMessageBox msg;
    msg.information(nullptr, "Reset",
                    "500: "+ QString::number(*p)+
                    "\n100: "+ QString::number(*(p+1))+
                    "\n50: "+ QString::number(*(p+2))+
                    "\n10: "+ QString::number(*(p+3)) );
    changemoney(0);
}
