#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sys/sysinfo.h"
#include <sys/resource.h>
#include <fstream>
#include <cstdlib>
#include "matriz_dinamica.h"
using namespace std;

int **puntero_matriz;
int nFilas = 5;
int nCol = 10;
string linea;

//*(*(puntero_matriz+i)+j)

//Se reserva la matriz en memoria
void rellenarMatriz(){
    ifstream archivo("disco.txt");
    puntero_matriz = new int*[nFilas]; //Reservando memoria para las filas
    for (int i = 0; i < nFilas; i++){
        puntero_matriz[i] = new int[nCol];  //Reservando memoria para las columnas
    }
    cout <<"Digitando elementos de la matriz" <<endl;
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            getline(archivo,linea);
            *(*(puntero_matriz+i)+j) = std::stoi(linea);
        }
    }
}


void mostrarMatriz(int **puntero_matriz, int nFilas, int nColumnas){
    cout << "Imprimiendo la matriz:" << endl;
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            cout << *(*(puntero_matriz+i)+j);
        }
        cout << "\n";
    
    /*
    //Liberar la memoria utilizada en la matriz
    for (int i = 0; i < nFilas; i++){
        delete[] puntero_matriz[i];
        puntero_matriz[i] = nullptr;
    }
    delete[] puntero_matriz;
    puntero_matriz = nullptr;
    */
    
    }
}

/*
int main(){
    rellenarMatriz();
    mostrarMatriz(puntero_matriz, nFilas, nCol);
    cout << "Fin del programa de matriz_dinamica" << endl;

    return 0;
}
*/