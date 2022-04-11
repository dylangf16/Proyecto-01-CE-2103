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

string buscar(int **puntero_matriz, int nFilas, int nCol, int num, string resul){
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            int num_matrix = *(*(puntero_matriz+i)+j);
            if(num_matrix == num){
                resul = "True";
                return resul;
            }
        }
    }
    return "False";
}

void eliminar_memoria(int **puntero_matriz, int nFilas, int nCol){
    //Liberar la memoria utilizada en la matriz
    for (int i = 0; i < nFilas; i++){
        free(puntero_matriz[i]);
        puntero_matriz[i] = nullptr;
    }
    free(puntero_matriz);
    puntero_matriz = nullptr;
}

//Se reserva la matriz en memoria
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
    
    //Obtiene la memoria usada por el programa utilizando lineas de comando
    int id = getpid();
    string string("pmap ");
    string.append(to_string(id));
    string.append(" | tail -n 1 | awk '/[0-9]K/{print $2}'");
    char const *pchar = string.c_str();
    cout << "ID del programa: " << id << endl;
    int memoria_usada = system(pchar);
    mostrarMatriz(puntero_matriz, nFilas, nCol);


    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::string resul = buscar(puntero_matriz,nFilas,nCol,stoi(num),"False");
    eliminar_memoria(puntero_matriz,nFilas,nCol);
    return resul;
}

/*
int main(){
    rellenarMatriz(8,7,"5");
    cout << "Fin del programa de matriz_dinamica" << endl;

    return 0;
}
*/

