#include "sys/sysinfo.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

using namespace std;
long get_mem_usage(){
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_maxrss;
}

int getmem(){
    struct sysinfo memInfo;
    sysinfo (&memInfo);

    long long totalPhysMem = memInfo.totalram;
    //Multiply in next statement to avoid int overflow on right hand side...
    totalPhysMem *= memInfo.mem_unit;
    totalPhysMem /= 800000;

    long long physMemUsed = memInfo.totalram - memInfo.freeram;
    physMemUsed *= memInfo.mem_unit;;
    physMemUsed/= 800000;

    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    cout << "Del método getmem() // RAM usada en KB: " << physMemUsed << endl;
    cout << "Del método getmem() //Ram total: " << totalPhysMem << endl;
    return physMemUsed;




}

int main() {
    int filas, columnas, total;
    cout<<"Digite el numero de filas: "; cin>>filas;
    cout<<"Digite el numero de columnas: "; cin>>columnas;

    int numeros[filas][columnas];

    //Rellenando la matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            int x = i + 2;
            int y = j + 2;
            int final;
            final += sizeof(numeros[i][j]);
            numeros[x][y];
            cout << "Memoria usada intento 1: " << final << endl;
            cout << "Memoria usada intento 2: " << getmem() << endl;
            total = final;
        }
    }

    int valor = sizeof(numeros);
    valor = valor * 138;
    cout <<"Tamaño de la matriz en la memoria en MB: " << valor << endl;
    cout << "Con método de google 1: " << total << endl;
    getchar();


}



