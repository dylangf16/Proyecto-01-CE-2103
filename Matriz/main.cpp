#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int card1 = 0;
int card2 = 0;
int card3 = 0;
int card4 = 0;
int card5 = 0;
int nFilas = 5;
int nCol = 10;
int numeros[5][10];


//Verificando que haya pares de todas las cartas
int verfi(int tipo){
    int entrada = tipo;
    if(tipo == 1 & card1 < 10){
        //TARJETAS t1(1,true,"img");
        card1+=1;
        return tipo;
    }
    if(tipo == 2 & card2 < 10){
        card2+=1;
        return tipo;
    }
    if(tipo == 3 & card3 < 10){
        card3+=1;
        return tipo;
    }
    if(tipo == 4 & card4 < 10){
        card4+=1;
        return tipo;
    }
    if(tipo == 5 & card5 < 10){
        card5+=1;
        return tipo;
    }
    else{
        int tipo = rand() % 5 + 1;
        return verfi(tipo);
    }
}

//Guarda la matriz en un txt para manipulación
void guardarmatrix(){
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
    srand(time(NULL));
    //Rellenando la matriz
    for(int i=0;i<nFilas;i++) {
        for (int j = 0; j < nCol; j++) {
            int tipo = 1+rand() % 6 - 1;
            numeros[i][j] = verfi(tipo);
        }
    }
    //Mostrando nFilas
    for(int i=0;i<nFilas;i++){
        for(int j=0;j<nCol;j++){
            cout << numeros[i][j];
        }
        cout << "\n";
    }

    guardarmatrix();

    return **numeros;
}
