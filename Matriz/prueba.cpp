#include <iostream>
using namespace std;
#include <stdlib.h>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Headers_Pruebas/Source_Files/Log.cpp"


int main(){
    InitLog();
    
    int num = Log("Hello world!");
    cout << num << endl;
}