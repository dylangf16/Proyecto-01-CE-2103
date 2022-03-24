#include <iostream>
#include <stdlib.h>


void Log(const char* message){
    std::cout << message << std::endl;
}

void InitLog(){
    Log("Empezar Log");
}