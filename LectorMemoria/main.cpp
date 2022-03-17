#include <iostream>
using namespace std;

#include "sys/sysinfo.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include <sys/resource.h>

int getPhys(){
    struct sysinfo memInfo;

    sysinfo (&memInfo);
    long long physMemUsed = memInfo.totalram - memInfo.freeram;
    //Multiply in next statement to avoid int overflow on right hand side...
    physMemUsed *= memInfo.mem_unit;
    physMemUsed /= 1000;
    return physMemUsed;
}
int getVirt(){
    struct sysinfo memInfo;

    sysinfo (&memInfo);
    long long virtualMemUsed = memInfo.totalram - memInfo.freeram;
    //Add other values in next statement to avoid int overflow on right hand side...
    virtualMemUsed += memInfo.totalswap - memInfo.freeswap;
    virtualMemUsed *= memInfo.mem_unit;
    virtualMemUsed /= 1000;
    return virtualMemUsed;
}

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getVirtCurrent(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

int getPhysCurrent(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}


// ---------------------------------------
long get_mem_usage(){
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_maxrss;
}
// 1658372 //  1660196 // 1661780
int main() {
    long baseline = get_mem_usage();

    int filas, columnas;
    cout<<"Digite el numero de filas: "; cin>>filas;
    cout<<"Digite el numero de columnas: "; cin>>columnas;

    int numeros[filas][columnas];

    //Rellenando la matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            int x = i+1;
            int y = j+1;
            numeros[y][x];
        }
    }

    cout << "Método memoria física en MB:          " << getPhys() << endl;
    cout << "                     " << endl;

    cout << "Método memoria virtual en MB:          " << getVirt() << endl;
    cout << "                     " << endl;

    cout << "Método memoria virtual usada AHORA MISMO en kb:          " << getVirtCurrent() << endl;
    cout << "                     " << endl;

    cout << "Método memoria física usada AHORA MISMO en kb:          " << getPhysCurrent() << endl;
    cout << "                     " << endl;

    cout << "Método rusage:          " << get_mem_usage() << endl;
    cout << "                     " << endl;
    getchar();

}



