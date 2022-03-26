#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
#include <fstream>
#include<stdlib.h>
using namespace std;

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
    int filas = 5;
    int columnas = 10;


/*
    int numeros = system("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/main");
    cout << numeros << endl;


    //Mostrando matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(*(*(matriz+i)+j) = 1){
                cout << "1" << endl;
            }
        }
        cout << "\n";
    }
    cout << "Hola" << endl;
    */
}

void MainWindow::on_btn_verif_clicked(){
     int nombre = system("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Servidor/main");
     cout << "Llegada a la interfaz" << endl;
     cout << nombre << endl;
}
