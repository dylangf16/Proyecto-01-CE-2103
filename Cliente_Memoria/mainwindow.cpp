#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
#include <fstream>
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



//Boton empezar
void MainWindow::on_btn_start_clicked(){
    ofstream matris;

    matris.open("/home/dylan16/Documents/Datos 2/Proyecto 01/Proyecto-01-CE-2103/Matriz/main.cpp", ios::out);
    cout << "Hola" << endl;
}
