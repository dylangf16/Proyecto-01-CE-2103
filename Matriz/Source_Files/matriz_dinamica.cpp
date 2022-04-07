#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>




using namespace std;
int **puntero_matriz;
string linea2;

void mostrarMatriz(int **puntero_matriz, int nFilas, int nCol){
    cout << "Imprimiendo la matriz en memoria:" << endl;
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            cout << *(*(puntero_matriz+i)+j);
        }
        cout << "\n";
    }
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
        delete[] puntero_matriz[i];
        puntero_matriz[i] = nullptr;
    }
    delete[] puntero_matriz;
    puntero_matriz = nullptr;
}

//Se reserva la matriz en memoria
string rellenarMatriz(int nFilas, int nCol, string num){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");

    /*
    //Reserva la memoria para las Filas
    for(int i = 0; i < nFilas; i++){
        int *p = (int*)malloc(1024*100);
        memset(p,1,1024*100);
    }

    //Reserva la memoria para las columnas
    for(int i = 0; i < nCol; i++){
        int *p = (int*)malloc(1024*100);
        memset(p,1,1024*100);
    }
    */
    //Establece un valor a cada posición de la matris dinámica
    int **puntero_matriz = (int**) malloc(nFilas*nCol);
    puntero_matriz = new int*[nFilas]; 
    for (int i = 0; i < nFilas; i++){
        puntero_matriz[i] = new int[nCol];
    }
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            getline(archivo,linea2);
            *(*(puntero_matriz+i)+j) = std::stoi(linea2);
        }
    }
    
    int id = getpid();
    string string("pmap ");
    string.append(to_string(id));
    string.append(" | tail -n 1 | awk '/[0-9]K/{print $2}'");
    char const *pchar = string.c_str();
    cout << id << endl;
    cout << system(pchar) << endl;


    mostrarMatriz(puntero_matriz, nFilas, nCol);
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::string resul = buscar(puntero_matriz,nFilas,nCol,stoi(num),"False");
    eliminar_memoria(puntero_matriz,nFilas,nCol);
    cout << system(pchar) << endl;
    return resul;
}


int main(){
    rellenarMatriz(1,2,"5");
    cout << "Fin del programa de matriz_dinamica" << endl;

    return 0;
}