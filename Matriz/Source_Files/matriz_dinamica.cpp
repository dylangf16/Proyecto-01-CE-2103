#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/memoria_ncurses.cpp"

using namespace std;
int **puntero_matriz;
string linea2;

//Muestra la matriz en memoria
//Esto lo hace recorriendo los punteros de punteros en memoria, y los va imprimiendo en forma de matriz en terminal
void mostrarMatriz(int **puntero_matriz, int nFilas, int nCol){
    cout << "Imprimiendo la matriz en memoria:" << endl;
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            cout << *(*(puntero_matriz+i)+j) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

//Buscar el valor recibido por el servidor en la matriz dinamica de punteros
string buscar(int **puntero_matriz, int nFilas, int nCol, int num, string resul){
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            int num_matrix = *(*(puntero_matriz+i)+j);
            if(num_matrix == num){
                resul = "True";
                cout << resul << endl;
                return resul;
            }
        }
    }
    cout << resul << endl;
    return "False";
}

//Libera la memoria de la matriz y les da un nullptr
void eliminar_memoria(int **puntero_matriz, int nFilas, int nCol){
    //Liberar la memoria utilizada en la matriz
    for (int i = 0; i < nFilas; i++){
        free(puntero_matriz[i]);
        puntero_matriz[i] = nullptr;
    }
    free(puntero_matriz);
    puntero_matriz = nullptr;
}

//Crea la matriz dinamica de punteros
string rellenarMatriz(int nFilas, int nCol, string num){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");

    //Establece un valor a cada posición de la matris dinámica
    puntero_matriz = (int**) malloc(1024*100); 
    for (int i = 0; i < nFilas; i++){
        puntero_matriz[i] = (int*) malloc(1024*100);
    }
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            getline(archivo,linea2);
            *(*(puntero_matriz+i)+j) = std::stoi(linea2);
        }
    }
    cout << "Memoria usada: " << (nFilas + nCol) * 8*2  << "k" << endl; //Cálculo de la memoria aproximada utilizada

    mostrarMatriz(puntero_matriz, nFilas, nCol);
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::string resul = buscar(puntero_matriz,nFilas,nCol,stoi(num),"False");
    eliminar_memoria(puntero_matriz,nFilas,nCol);
    return resul;
}

/*
int main(){
    rellenarMatriz(2,3,"5");
    cout << "Fin del programa de matriz_dinamica" << endl;

    return 0;
}
*/

