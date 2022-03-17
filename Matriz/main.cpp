#include <iostream>
using namespace std;

int card1 = 0;
int card2 = 0;
int card3 = 0;
int card4 = 0;
int card5 = 0;

int verfi(int tipo){
    int entrada = tipo;
    if(tipo == 1 & card1 < 10){
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
    int filas, columnas;
    cout<<"Digite el numero de filas: "; cin>>filas;
    cout<<"Digite el numero de columnas: "; cin>>columnas;

    int numeros[filas][columnas];

    //Rellenando la matriz
    for(int i=0;i<filas;i++) {
        for (int j = 0; j < columnas; j++) {
            int tipo = rand() % 5 + 1;
            numeros[i][j] = verfi(tipo);
        }
    }

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << numeros[i][j];
        }
        cout << "\n";
    }

    cout << "Cartas tipo 1: " << card1 << endl;
    cout << "Cartas tipo 2: " << card2 << endl;
    cout << "Cartas tipo 3: " << card3 << endl;
    cout << "Cartas tipo 4: " << card4 << endl;
    cout << "Cartas tipo 5: " << card5 << endl;
}
