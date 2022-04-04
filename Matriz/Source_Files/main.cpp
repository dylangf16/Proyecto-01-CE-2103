#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int card11 = 0;
int card21 = 0;
int card31 = 0;
int card41 = 0;
int card51 = 0;
int nFilas = 6;
int nCol = 10;

int numeros[6][10];


//Verificando que haya pares de todas las cartas
int verfi1(int tipo){
    int entrada = tipo;
    if(tipo == 1 & card11 < 12){
        //TARJETAS t1(1,true,"img");
        card11+=1;
        return tipo;
    }
    if(tipo == 2 & card21 < 12){
        card21+=1;
        return tipo;
    }
    if(tipo == 3 & card31 < 12){
        card31+=1;
        return tipo;
    }
    if(tipo == 4 & card41 < 12){
        card41+=1;
        return tipo;
    }
    if(tipo == 5 & card51 < 12){
        card51+=1;
        return tipo;
    }
    else{
        int tipo = rand() % 5 + 1;
        return verfi1(tipo);
    }
}

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

void generarMatriz(){
    srand(time(NULL));
    //Rellenando la matriz
    for(int i=0;i<nFilas;i++) {
        for (int j = 0; j < nCol; j++) {
            int tipo = 1+rand() % 6 - 1;
            numeros[i][j] = verfi1(tipo);
            //numeros[i][j] = num ////// num = 0 /// num++;
        }
    }
    guardarmatrix();
    
    //Mostrando nFilas
    for(int i=0;i<nFilas;i++){
        for(int j=0;j<nCol;j++){
            cout << numeros[i][j];
        }
        cout << "\n";
    }
}

//Guarda la matriz en un txt para manipulación

/*
int main() {
    //En clase Matriz
    //generarMatriz();
    //guardarmatrix();
    //guardarmatrix2();

    //En clase matriz_dinamica
    rellenarMatriz(4,5);

    return **numeros;
}
*/
