#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
map<string,string> MisCartas;

void guardar(){
    ifstream archivo("hash.txt");
    string linea;
    string texto;
    while (getline(archivo,linea)){
        texto = texto + linea;
    }
    archivo.close();

    ofstream archivo2("hash.txt");
    for (auto pair: MisCartas){
        archivo2 << pair.first << pair.second << "\n";
    }
    archivo2.close();
}


int main(){
    for (int i = 0; i < 150; i++){
        MisCartas.insert(pair<string,string>(to_string(i),"img"));
    }

    for(auto pair : MisCartas){
        cout << pair.first << " - " << pair.second << endl;
    }

    guardar();
    
    return 0;
}