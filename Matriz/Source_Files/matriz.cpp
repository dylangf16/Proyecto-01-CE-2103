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
string linea3;

//Guarda la matriz en memoria
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

//Guarda la matriz en memoria
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

//Escoge una columna aleatoria para cambiar de posición
int aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

//Revuelve la matriz obtenida del txt
void revolverMatriz(){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");
    srand(time(NULL));
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

//Genera la matriz original ordenada de mayor a menor
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

//Muestra la matriz en terminal
void mostrar_matriz_disco(int nFilasMem, int nColMem){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");
    int contador = 0;
    int lim = nFilasMem*nColMem;
    cout << "Imprimiendo la matriz en disco" << endl;
    for (int i = 0; i < nFilas; i++){
        for (int j = 0; j < nCol; j++){
            if(contador >= lim){
                getline(archivo,linea3);
                cout << linea3 << " ";
            }else{
                getline(archivo,linea3);
                contador++;
            }
        }
        cout << "\n";
    }
    cout << "\n";
    
}

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
