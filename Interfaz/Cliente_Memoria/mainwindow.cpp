#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
#include <fstream>
#include<stdlib.h>
#include <cstdlib>
//#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/Hashmap.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz_dinamica.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Servidor/Source_Files/Cliente.cpp"
//#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Servidor/Source_Files/Server.cpp"
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
}

//Boton verificar
void MainWindow::on_btn_verif_clicked(){

}

//Carta 0
void MainWindow::on_pushButton_0_clicked()
{
    if(carta1 == NULL){
        carta1 = 0;
    }
    if(carta2 == NULL){
        carta2 = 0;
    }
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "0";
    string img = Cliente(0,0,num);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_0-> setIcon(QIcon(qstr));
}

void MainWindow::on_pushButton_1_clicked()
{
    if(carta1 == NULL){
        carta1 = 1;
    }
    if(carta2 == NULL){
        carta2 = 1;
    }
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "1";
    /*
    string img = buscar(0,0,num);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_1-> setIcon(QIcon(qstr));
    */
}


void MainWindow::on_pushButton_2_clicked()
{
    if(carta1 == NULL){
        carta1 = 2;
    }
    if(carta2 == NULL){
        carta2 = 2;
    }
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "2";
    /*
    string img = buscar(0,0,num);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_2-> setIcon(QIcon(qstr));
    */

}


void MainWindow::on_pushButton_3_clicked()
{
    if(carta1 == NULL){
        carta1 = 3;
    }
    if(carta2 == NULL){
        carta2 = 3;
    }
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "3";
    /*
    string img = buscar(0,0,num);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_3-> setIcon(QIcon(qstr));
    */

}
