#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include <iostream>
using namespace std;

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

void MainWindow::on_zero_clicked()
{
    this->input+="0";
    this->ui->LCD->setText(input);
}

void MainWindow::on_one_clicked()
{
    this->input+="1";
    this->ui->LCD->setText(input);

}

void MainWindow::on_two_clicked()
{
    this->input+="2";
    this->ui->LCD->setText(input);
}

void MainWindow::on_three_clicked()
{
    this->input+="3";
    this->ui->LCD->setText(input);
}

void MainWindow::on_four_clicked()
{
    this->input+="4";
    this->ui->LCD->setText(input);
}

void MainWindow::on_five_clicked()
{
    this->input+="5";
    this->ui->LCD->setText(input);
}

void MainWindow::on_six_clicked()
{
    this->input+="6";
    this->ui->LCD->setText(input);
}

void MainWindow::on_seven_clicked()
{
    this->input+="7";
    this->ui->LCD->setText(input);
}

void MainWindow::on_eight_clicked()
{
    this->input+="8";
    this->ui->LCD->setText(input);
}

void MainWindow::on_nine_clicked()
{
    this->input+="9";
    this->ui->LCD->setText(input);

}

void MainWindow::on_openingParenthesis_clicked()
{
    this->input+="(";
    this->ui->LCD->setText(input);

}

void MainWindow::on_closing_parenthesis_clicked()
{
    this->input+=")";
    this->ui->LCD->setText(input);
}

void MainWindow::on_point_clicked()
{
    this->input+=".";
    this->ui->LCD->setText(input);

}

void MainWindow::on_divide_clicked()
{
    this->input+="/";
    this->ui->LCD->setText(input);
}

void MainWindow::on_pushButton_clicked()
{
    this->input+="X";
    this->ui->LCD->setText(input);
}

void MainWindow::on_plus_clicked()
{
    this->input+="+";
    this->ui->LCD->setText(input);
}

void MainWindow::on_minus_clicked()
{
    this->input+="-";
    this->ui->LCD->setText(input);
}

void MainWindow::on_clearAll_clicked()
{
    this->input="";
    this->ui->LCD->setText(input);
    this->ui->equal->setDisabled(false);
}

void MainWindow::on_backspace_clicked()
{
    QString temp_string;
    for ( int i=0; i<this->input.size()-1; i++)
    {
        temp_string[i]= this->input[i];
    }

     this->input= temp_string;
    this->ui->LCD->setText(input);
}

void MainWindow::on_equal_clicked()
{

    if (input.size()==0)
        return;

    Controller c(this->input);
     this->input+="=" + QString::number(c.getAnswer());

     this->ui->LCD->setText(input);
    this->ui->equal->setDisabled(true);

}
