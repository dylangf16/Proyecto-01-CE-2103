#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
#include <fstream>
#include<stdlib.h>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/Hashmap.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz_dinamica.cpp"
using namespace std;
int carta1 = NULL;
int carta2 = NULL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}



//Boton empezar
void MainWindow::on_btn_start_clicked(){
    ui->pushButton_41->setIcon(QPixmap("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Interfaz/Cliente_Memoria/imagenes/SW_1.jpg"));
}

//Boton verificar
void MainWindow::on_btn_verif_clicked(){

}

void MainWindow::on_pushButton_0_clicked()
{
    if(carta1 == NULL){
        carta1 = 0;
    }
    if(carta2 == NULL){
        carta2 = 0;
    }
    rellenarMatriz(4,5);
    //ui -> pushButton_0-> setIcon(icon);


}
