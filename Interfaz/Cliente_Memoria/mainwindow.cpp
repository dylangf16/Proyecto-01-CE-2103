#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
#include <fstream>
#include<stdlib.h>
#include <cstdlib>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Servidor/Source_Files/Cliente.cpp"
using namespace std;

string carta1 = "NULL";
string carta2 = "NULL";
QString jugador1 = "Tzalil";
QString jugador2 = "Carkis";

QPushButton* carta_jugada1;
QPushButton* carta_jugada2;

bool turno = true;
int puntaje_jugador1 = 0;
int puntaje_jugador2 = 0;

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

//Boton verificar igualdad de cartas
void MainWindow::on_btn_verif_clicked(){
    string img = ":/imagenes/SW_back.jpg";
    QString qstr = QString::fromStdString(img);

    //Condicion de que ambas cartas son iguales
    if(carta1 == carta2){
        if (turno == true){
            cout << "Cartas iguales" << endl;
            puntaje_jugador1 = puntaje_jugador1 + 1;
            QString s = QString::number(puntaje_jugador1);
            ui->pts_jugador1->setText(s);
            turno = false;
            ui->turno->setText(jugador2);
            carta1 = "NULL";
            carta2 = "NULL";

            carta_jugada1->setDisabled(true);
            carta_jugada2->setDisabled(true);


        }else{
            puntaje_jugador2 = puntaje_jugador2 + 1;
            QString s = QString::number(puntaje_jugador2);
            ui->pts_jugador2->setText(s);
            turno = true;
            carta1 = "NULL";
            carta2 = "NULL";
            ui->turno->setText(jugador1);

            carta_jugada1->setDisabled(true);
            carta_jugada2->setDisabled(true);
        }
    //Condicion ambas cartas son diferentes
    } else{
        if (turno == true){
            turno = false;
            carta1 = "NULL";
            carta2 = "NULL";
            ui->turno->setText(jugador2);
            carta_jugada1->setIcon(QIcon(qstr));
            carta_jugada2->setIcon(QIcon(qstr));

        } else{
            turno = true;
            carta1 = "NULL";
            carta2 = "NULL";
            ui->turno->setText(jugador1);
            carta_jugada1->setIcon(QIcon(qstr));
            carta_jugada2->setIcon(QIcon(qstr));
        }
        carta_jugada1->setIcon(QIcon(qstr));
        carta_jugada2->setIcon(QIcon(qstr));
    }
}

int buscar_carta_presionada(){

    return 0;
}
//Carta 0
void MainWindow::on_pushButton_0_clicked()
{
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "0";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_0-> setIcon(QIcon(qstr));


    if(carta1 == "NULL"){
        carta1 = img;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
    }
    else{
        carta2 = img;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "1";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_1-> setIcon(QIcon(qstr));
    cout << "Imagen 1: " << img << endl;


    if(carta1 == "NULL"){
        carta1 = img;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
    }
    else{
        carta2 = img;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "2";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen 2: " << img << endl;
    ui -> pushButton_2-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
    }
    if(carta2 == "NULL"){
       carta2 = img;
       carta_jugada2=qobject_cast<QPushButton*>(sender());
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    //Método para arreglar "dos mains" solo ejecutar, tirar error, y luego comentar y seguir
    //rellenarMatriz(4,5);

    string num = "3";
    /*
    string img = buscar(0,0,num);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_3-> setIcon(QIcon(qstr));
    */
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_3-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
    }

}
