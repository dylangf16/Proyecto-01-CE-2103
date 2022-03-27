#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
map<string,string> MisCartas;
map<string,string> MisCartas2;
string linea;

//Guarda el hashmap con la información de cada casilla en un txt
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
        archivo2 << pair.first + "-"<< pair.second << "\n";
    }
    archivo2.close();
}
//Permite la búsqueda de la imágen según el número de la carta
string buscar(string s, int init, int end){
    ifstream archivo("hash.txt");
    string linea;
    string texto;
    int i = 0;
    while (i < 500){
        getline(archivo,linea);
        cout << linea << endl;
        while (end = linea.find("-", init), end >=0){
            if(linea.substr(init, end - init) == "15"){
                init = end + 1;
                return linea.substr(init, end - init);
            }
            i++;
            getline(archivo,linea);
        }
        i++;
    }
    return "jeje";
}


int main(){
    for (int i = 0; i < 60; i++){
        MisCartas.insert(pair<string,string>(to_string(i),"imagen"));
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
    string s = buscar(s,0,0);
    cout << s << endl;

    return 0;
}
