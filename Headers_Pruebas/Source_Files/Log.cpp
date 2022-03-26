#include <iostream>
#include <stdlib.h>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Headers_Pruebas/Headers_Files/Log.h"


int Log(const char* message){
    std::cout << message << std::endl;

    return 0;
}

void InitLog(){
    Log("Empezar Log");
}