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

void revisión(){
    string 
    while (getline(archivo,linea)){
        texto = texto + linea;
    }
}


int main(){
    for (int i = 0; i < 150; i++){
        MisCartas.insert(pair<string,string>(to_string(i),"img"));
    }

    for(auto pair : MisCartas){
        int i = 0;
        cout << pair.first << " - " << pair.second << endl;
        if (std::stoi(pair.first) == 9){
            cout << "Valor 9 encontrado!!!!!!!"<< endl;
            cout << pair.second << endl;
        }
    }

    

    guardar();
    
    return 0;
}