#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long get_mem_usage(){
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_nsignals;
}


void MainWindow::on_pushButton_clicked(){

    QPixmap pix("/home/dylan16/Documents/Datos 2/Proyecto 01/Proyecto-01-CE-2103/Cliente_Memoria/imagenes/SW_5.jpg");
    ui -> pushButton ->setIcon(pix);
    cout << "hola" << endl;
}
