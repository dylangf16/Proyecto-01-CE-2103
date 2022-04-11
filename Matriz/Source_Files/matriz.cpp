#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int nFilas = 6;
int nCol = 10;
int numeros[6][10];
int numeros2[6][10];

void guardarmatrix(){
    ofstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");
    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            archivo << numeros[i][j];
            archivo << endl;
        }
    }
    archivo.close();
}
void guardarmatrix2(){
    ofstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");
    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            archivo << numeros2[i][j];
            archivo << endl;
        }
    }
    archivo.close();
}

int aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


void revolverMatriz(){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            std::string linea;
            getline(archivo,linea);
            int num = stoi(linea);
            numeros2[i][j] = num;
        }
    }
    int longitud = sizeof(numeros2) / sizeof(numeros2[0]);

    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            int indiceAleatorio = aleatorio_en_rango(0, longitud - 1);
            // Intercambiar el actual con un elemento del índice aleatorio
            int temporal = numeros2[i][j];
            numeros2[i][j] = numeros2[indiceAleatorio][j];
            numeros2[indiceAleatorio][j] = temporal;
        }
    }
    guardarmatrix2();
}

void generarMatriz(){
    int num = 0;
    //Rellenando la matriz
    for(int i=0;i<nFilas;i++) {
        for (int j = 0; j < nCol; j++) {
            numeros[i][j] = num;
            num++;
        }
    }
    guardarmatrix();
    revolverMatriz();
    guardarmatrix2();
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
