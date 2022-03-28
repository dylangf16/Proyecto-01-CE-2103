#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz_dinamica.cpp"
using namespace std;

int card1 = 0;
int card2 = 0;
int card3 = 0;
int card4 = 0;
int card5 = 0;
int nFilas = 6;
int nCol = 10;

int numeros[6][10];


//Verificando que haya pares de todas las cartas
int verfi(int tipo){
    int entrada = tipo;
    if(tipo == 1 & card1 < 12){
        //TARJETAS t1(1,true,"img");
        card1+=1;
        return tipo;
    }
    if(tipo == 2 & card2 < 12){
        card2+=1;
        return tipo;
    }
    if(tipo == 3 & card3 < 12){
        card3+=1;
        return tipo;
    }
    if(tipo == 4 & card4 < 12){
        card4+=1;
        return tipo;
    }
    if(tipo == 5 & card5 < 12){
        card5+=1;
        return tipo;
    }
    else{
        int tipo = rand() % 5 + 1;
        return verfi(tipo);
    }
}

void generarMatriz(){
    srand(time(NULL));
    //Rellenando la matriz
    for(int i=0;i<nFilas;i++) {
        for (int j = 0; j < nCol; j++) {
            int tipo = 1+rand() % 6 - 1;
            numeros[i][j] = verfi(tipo);
            //numeros[i][j] = num ////// num = 0 /// num++;
        }
    }

    //Mostrando nFilas
    for(int i=0;i<nFilas;i++){
        for(int j=0;j<nCol;j++){
            cout << numeros[i][j];
        }
        cout << "\n";
    }
}

//Guarda la matriz en un txt para manipulación
void guardarmatrix(){
    cout << "Guardando matriz en disco" << endl;
    ofstream archivo("disco.txt");
    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            archivo << numeros[i][j];
            archivo << endl;
        }
    }
    archivo.close();
}


int main() {
    //En clase Matriz
    //generarMatriz();
    //guardarmatrix();
    //guardarmatrix2();

    //En clase matriz_dinamica
    rellenarMatriz(4,5);

    return **numeros;
}
