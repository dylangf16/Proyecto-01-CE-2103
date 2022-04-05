#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <iostream>
#include <sys/resource.h>
#include <fstream>
#include<stdlib.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Servidor/Source_Files/Cliente.cpp"
using namespace std;

string carta1 = "NULL";
string carta2 = "NULL";
QString jugador1;
QString jugador2;
string carta1_mem = "False";
string carta2_mem = "False";
string num;

QPushButton* carta_jugada1;
QPushButton* carta_jugada1_1;
QPushButton* carta_jugada2;
QPushButton* carta_jugada2_2;

bool turno = true;

int i = 5;
int j = 4;
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
    Cliente("Start","0","0","0","0");
    ui -> name_jugador1 -> setText(ui->lineEdit->text());
    jugador1 = ui->lineEdit->text();
    ui -> name_jugador2 -> setText(ui->lineEdit_2->text());
    jugador2 =ui->lineEdit_2->text();

    ui -> btn_start ->setDisabled(true);
    ui -> lineEdit -> setDisabled(true);
    ui -> lineEdit_2 -> setDisabled(true);
    ui -> btn_verif ->setDisabled(false);
}


//Boton verificar igualdad de cartas
void MainWindow::on_btn_verif_clicked(){
    string img = ":/imagenes/SW_back.jpg";
    QString qstr = QString::fromStdString(img);

    carta_jugada1_1 = carta_jugada1;
    carta_jugada2_2 = carta_jugada1;

    if(puntaje_jugador1 == 5 || puntaje_jugador2 == 5){
        ui->pwup_1->setDisabled(false);
    }
    if(puntaje_jugador1 == 10 || puntaje_jugador2 == 10){
        ui->pwup_2->setDisabled(false);
    }
    if(puntaje_jugador1 == 15 || puntaje_jugador2 == 15){
        ui->pwup_2->setDisabled(false);
    }

    //Condicion de que ambas cartas son iguales
    if(carta1 == carta2){
        if (turno == true){
            cout << "Cartas iguales" << endl;
            if((carta1_mem == "True") & (carta2_mem == "True")){
                cout << "Cartas en memoria" << endl;
                puntaje_jugador1 = puntaje_jugador1 + 1;
                carta1_mem = "False";
                carta2_mem = "False";
            }
            puntaje_jugador1 = puntaje_jugador1 + 1;
            QString s = QString::number(puntaje_jugador1);
            ui->pts_jugador1->setText(s);
            turno = false;
            ui->turno->setText(jugador2);
            carta1 = "NULL";
            carta2 = "NULL";
            carta_jugada1->setDisabled(true);
            carta_jugada2->setDisabled(true);
            Cliente("Mix","0","0","0","0");



        }else{
            if((carta1_mem == "True") & (carta2_mem == "True")){
                puntaje_jugador1 = puntaje_jugador1 + 1;
                carta1_mem = "False";
                carta2_mem = "False";
            }
            puntaje_jugador2 = puntaje_jugador2 + 1;
            QString s = QString::number(puntaje_jugador2);
            ui->pts_jugador2->setText(s);
            turno = true;
            carta1 = "NULL";
            carta2 = "NULL";
            ui->turno->setText(jugador1);

            carta_jugada1->setDisabled(true);
            carta_jugada2->setDisabled(true);
            Cliente("Mix","0","0","0","0");
        }
        Cliente("Mix","0","0","0","0");
        if(i != 1){
            i = i - 1;
        }
        if(j != 1){
            j = j - 1;
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

    num =  "0";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_0-> setIcon(QIcon(qstr));


    if(carta1 == "NULL"){
        carta1 = img;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);

    }
    else{
        carta2 = img;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    num =  "1";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    ui -> pushButton_1-> setIcon(QIcon(qstr));
    cout << "Imagen 1: " << img << endl;


    if(carta1 == "NULL"){
        carta1 = img;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    num =  "2";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen 2: " << img << endl;
    ui -> pushButton_2-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    if(carta2 == "NULL"){
       carta2 = img;
       carta_jugada2=qobject_cast<QPushButton*>(sender());
       carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    num =  "3";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_3-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);

    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);

    }

}

void MainWindow::on_pushButton_4_clicked()
{
    num =  "4";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_4-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    num =  "5";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_5-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    num =  "6";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_6-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    num =  "7";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_7-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }

}

void MainWindow::on_pushButton_8_clicked()
{
    num =  "8";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_8-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    num =  "9";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_9-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    num =  "10";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_10-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    num =  "11";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_11-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    num =  "12";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_12-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    num =  "13";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_13-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    num =  "14";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_14-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    num =  "15";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_15-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    num =  "16";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_16-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    num =  "17";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_17-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    num =  "18";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_18-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_19_clicked()
{
    num =  "19";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_19-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_20_clicked()
{
    num =  "20";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_20-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_21_clicked()
{
    num =  "21";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_21-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_22_clicked()
{
    num =  "22";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_22-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_23_clicked()
{
    num =  "23";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_23-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_24_clicked()
{
    num =  "24";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_24-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_25_clicked()
{
    num =  "25";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_25-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_26_clicked()
{
    num =  "26";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_26-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_27_clicked()
{
    num =  "27";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_27-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_28_clicked()
{
    num =  "28";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_28-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_29_clicked()
{
    num =  "29";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_29-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_30_clicked()
{
    num =  "30";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_30-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_31_clicked()
{
    num =  "31";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_31-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_32_clicked()
{
    num =  "32";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_32-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_33_clicked()
{
    num =  "33";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_33-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_34_clicked()
{
    num =  "34";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_34-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_35_clicked()
{
    num =  "35";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_35-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_36_clicked()
{
    num =  "36";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_36-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_37_clicked()
{
    num =  "37";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_37-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_38_clicked()
{
    num =  "38";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_38-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_39_clicked()
{
    num =  "39";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_39-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_40_clicked()
{
    num =  "40";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_40-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_41_clicked()
{
    num =  "41";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_41-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_42_clicked()
{
    num =  "42";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_42-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_43_clicked()
{
    num =  "43";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_43-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_44_clicked()
{
    num =  "44";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_44-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_45_clicked()
{
    num =  "45";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_45-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_46_clicked()
{
    num =  "46";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_46-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_47_clicked()
{
    num =  "47";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_47-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_48_clicked()
{
    num =  "48";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_48-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_49_clicked()
{
    num =  "49";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_49-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_50_clicked()
{
    num =  "50";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_50-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_51_clicked()
{
    num =  "51";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_51-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_52_clicked()
{
    num =  "52";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_52-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_53_clicked()
{
    num =  "53";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_53-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_54_clicked()
{
    num =  "54";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_54-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_55_clicked()
{
    num =  "55";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_55-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_56_clicked()
{
    num =  "56";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_56-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_57_clicked()
{
    num =  "57";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_57-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_58_clicked()
{
    num =  "58";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_58-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pushButton_59_clicked()
{
    num =  "59";
    string img = Cliente("IMG",num,"0","0","0");
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_59-> setIcon(QIcon(qstr));

    if(carta1 == "NULL"){
        carta1 = img;
        cout << carta1 << endl;
        carta_jugada1=qobject_cast<QPushButton*>(sender());
        carta1_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
    else{
        carta2 = img;
        cout << carta2 << endl;
        carta_jugada2=qobject_cast<QPushButton*>(sender());
        carta2_mem = Cliente("Matrix_mem",num,to_string(i),to_string(j),num);
    }
}

void MainWindow::on_pwup_1_clicked()
{
    i +=3;
    j +=3;
    Cliente("Matrix_mem",num,to_string(i),to_string(j),"0");
}
