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
    string num = "3";
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

void MainWindow::on_pushButton_4_clicked()
{
    string num = "4";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_4-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_5_clicked()
{
    string num = "5";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_5-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_6_clicked()
{
    string num = "6";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_6-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_7_clicked()
{
    string num = "7";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_7-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_8_clicked()
{
    string num = "8";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_8-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_9_clicked()
{
    string num = "9";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_9-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_10_clicked()
{
    string num = "10";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_10-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_11_clicked()
{
    string num = "1";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_11-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_12_clicked()
{
    string num = "12";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_12-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_13_clicked()
{
    string num = "13";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_13-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_14_clicked()
{
    string num = "14";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_14-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_15_clicked()
{
    string num = "15";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_15-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_16_clicked()
{
    string num = "16";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_16-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_17_clicked()
{
    string num = "17";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_17-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_18_clicked()
{
    string num = "18";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_18-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_19_clicked()
{
    string num = "19";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_19-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_20_clicked()
{
    string num = "20";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_20-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_21_clicked()
{
    string num = "21";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_21-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_22_clicked()
{
    string num = "22";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_22-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_23_clicked()
{
    string num = "23";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_23-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_24_clicked()
{
    string num = "24";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_24-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_25_clicked()
{
    string num = "25";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_25-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_26_clicked()
{
    string num = "26";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_26-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_27_clicked()
{
    string num = "27";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_27-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_28_clicked()
{
    string num = "28";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_28-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_29_clicked()
{
    string num = "29";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_29-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_30_clicked()
{
    string num = "30";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_30-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_31_clicked()
{
    string num = "31";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_31-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_32_clicked()
{
    string num = "32";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_32-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_33_clicked()
{
    string num = "33";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_33-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_34_clicked()
{
    string num = "34";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_34-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_35_clicked()
{
    string num = "35";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_35-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_36_clicked()
{
    string num = "36";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_36-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_37_clicked()
{
    string num = "37";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_37-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_38_clicked()
{
    string num = "38";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_38-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_39_clicked()
{
    string num = "39";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_39-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_40_clicked()
{
    string num = "40";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_40-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_41_clicked()
{
    string num = "41";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_41-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_42_clicked()
{
    string num = "42";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_42-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_43_clicked()
{
    string num = "43";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_43-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_44_clicked()
{
    string num = "44";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_44-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_45_clicked()
{
    string num = "45";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_45-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_46_clicked()
{
    string num = "46";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_46-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_47_clicked()
{
    string num = "47";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_47-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_48_clicked()
{
    string num = "48";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_48-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_49_clicked()
{
    string num = "49";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_49-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_50_clicked()
{
    string num = "50";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_50-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_51_clicked()
{
    string num = "51";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_51-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_52_clicked()
{
    string num = "52";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_52-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_53_clicked()
{
    string num = "53";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_53-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_54_clicked()
{
    string num = "54";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_54-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_55_clicked()
{
    string num = "55";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_55-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_56_clicked()
{
    string num = "56";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_56-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_57_clicked()
{
    string num = "57";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_57-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_58_clicked()
{
    string num = "58";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_58-> setIcon(QIcon(qstr));

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

void MainWindow::on_pushButton_59_clicked()
{
    string num = "59";
    string img = Cliente(num);
    img.erase(img.end() -1);
    QString qstr = QString::fromStdString(img);
    cout << "Imagen: " << img << endl;
    ui -> pushButton_59-> setIcon(QIcon(qstr));

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
