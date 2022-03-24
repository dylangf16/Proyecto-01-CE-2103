#include <iostream>
#include <stdlib.h>


int Log(const char* message){
    std::cout << message << std::endl;

    return 0;
}

void InitLog(){
    Log("Empezar Log");
}