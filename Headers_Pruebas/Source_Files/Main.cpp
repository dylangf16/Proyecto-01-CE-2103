#include <iostream>
#include <stdlib.h>
#include "Log.cpp"


int main(){
    InitLog();
    Log("Hello world!");
    std::cin.get();
}