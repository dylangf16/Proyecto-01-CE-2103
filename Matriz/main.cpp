#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
/*
//Clase padre de todas las tarjetas
class TARJETAS{
private:
    int id;
    bool jugando;
    string img;

public:
    TARJETAS(int,bool,string);
    int darId();
    bool darJugando();
    string darImg();
};
//Constructor de TARJETAS
TARJETAS :: TARJETAS(int _id, bool _jugando, string _img) {
    id = _id;
    jugando = _jugando;
    img = _img;
}
//Método para dar ID de las Tarjetas
int TARJETAS::darId() {
    return id;
}

bool TARJETAS::darJugando() {
    return jugando;
}
string TARJETAS::darImg() {
    return img;
}
 */

int card1 = 0;
int card2 = 0;
int card3 = 0;
int card4 = 0;
int card5 = 0;

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
    //numeros[i][j] = tipo;
}

int main() {
    int filas = 5;
    int columnas = 10;
    int numeros[filas][columnas];
    srand(time(NULL));

    //Rellenando la matriz
    for(int i=0;i<filas;i++) {
        for (int j = 0; j < columnas; j++) {
            int tipo = 1+rand() % 6 - 1;
            numeros[i][j] = verfi(tipo);
        }
    }
    //Mostrando matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << numeros[i][j];
        }
        cout << "\n";
    }

    cout << "Cantidad de 1: " << card1 << endl;
    cout << "Cantidad de 2: " << card2 << endl;
    cout << "Cantidad de 3: " << card3 << endl;
    cout << "Cantidad de 4: " << card4 << endl;
    cout << "Cantidad de 5: " << card5 << endl;

    cout << numeros << endl;
    return 0;
}
