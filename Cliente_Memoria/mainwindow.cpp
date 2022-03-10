#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPixmap pix("/home/dylan16/Documents/Datos 2/Proyecto 01/Proyecto-01-CE-2103/Cliente_Memoria/imagenes/SW_5.jpg");
    ui -> pushButton ->setIcon(pix);
}
