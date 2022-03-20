#include <iostream>
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "sys/sysinfo.h"
#include <sys/resource.h>
using namespace std;

int **puntero_matriz;
int nFilas = 5;
int nCol = 10;
int card1 = 0;
int card2 = 0;
int card3 = 0;
int card4 = 0;
int card5 = 0;

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
    //numeros[i][j] = tipo;
}


//Se reserva la matriz en memoria
void rellenarMatriz(){
    srand(time(NULL));
    puntero_matriz = new int*[nFilas]; //Reservando memoria para las filas
    for (int i = 0; i < nFilas; i++){
        puntero_matriz[i] = new int[nCol];  //Reservando memoria para las columnas
    }
    cout <<"Digitando elementos de la matriz" <<endl;
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            int tipo = 1+rand() % 6 - 1;
            *(*(puntero_matriz+i)+j) = verfi(tipo);
            
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
    } 
}

int main(){
    rellenarMatriz();
    mostrarMatriz(puntero_matriz, nFilas, nCol);
    
    
    //Liberar la memoria utilizada en la matriz
    for (int i = 0; i < nFilas; i++){
        delete[] puntero_matriz[i];
        puntero_matriz[i] = nullptr;
    }
    delete[] puntero_matriz;
    puntero_matriz = nullptr;

    
    /*
    cout << "Cantidad de 1: " << card1 << endl;
    cout << "Cantidad de 2: " << card2 << endl;
    cout << "Cantidad de 3: " << card3 << endl;
    cout << "Cantidad de 4: " << card4 << endl;
    cout << "Cantidad de 5: " << card5 << endl;
    cout << &puntero_matriz << endl;
    cout << puntero_matriz[0][0] << endl;
    */
    cout << "Fin del programa de matriz_dinamica" << endl;

    return **puntero_matriz;
}