#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main (){

    int init = 0;
    int end = 0;
    string valor;

    std::string linea = "Matrix_mem-4-5-18-98-pepe-juana";
    while (end = linea.find("-", init), end >=0){
        valor = linea.substr(init, end-init);
        cout << valor << endl;
        init = end +1;
    }
    valor = linea.substr(init, end-init);
    cout << valor << endl;

    return 0;
}