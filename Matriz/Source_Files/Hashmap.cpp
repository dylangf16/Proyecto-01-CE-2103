#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
map<string,string> MisCartas;
map<string,string> MisCartas2;
string linea;
int card1 = 0;
int card2 = 0;
int card3 = 0;
int card4 = 0;
int card5 = 0;


string verfi(int tipo){
    if(tipo == 1 & card1 < 12){
        string img = "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Interfaz/Cliente_Memoria/imagenes/SW_1.jpg";
        card1+=1;
        return img;
    }
    if(tipo == 2 & card2 < 12){
        string img = "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Interfaz/Cliente_Memoria/imagenes/SW_2.jpg";
        card2+=1;
        return img;
    }
    if(tipo == 3 & card3 < 12){
        string img = "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Interfaz/Cliente_Memoria/imagenes/SW_3.jpg";
        card3+=1;
        return img;
    }
    if(tipo == 4 & card4 < 12){
        string img = "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Interfaz/Cliente_Memoria/imagenes/SW_4.jpg";
        card4+=1;
        return img;
    }
    if(tipo == 5 & card5 < 12){
        string img = "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Interfaz/Cliente_Memoria/imagenes/SW_5.jpg";
        card5+=1;
        return img;
    }
    else{
        int tipo = rand() % 5 + 1;
        return verfi(tipo);
    }
}

//Guarda el hashmap con la información de cada casilla en un txt
void guardar(){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/hash.txt");
    string linea;
    string texto;
    while (getline(archivo,linea)){
        texto = texto + linea;
    }
    archivo.close();

    ofstream archivo2("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/hash.txt");
    for (auto pair: MisCartas){
        archivo2 << pair.first + "-"<< pair.second << "\n";
    }
    archivo2.close();
}

//Genera el hashmap inicial según la matriz
void generarHash(){
    srand(time(NULL));
    for (int i = 0; i < 60; i++){
        int tipo = 1+rand() % 6 - 1;
        MisCartas.insert(pair<string,string>(to_string(i),verfi(tipo)));
    }
    guardar();
}


//Permite la búsqueda de la imágen según el número de la carta
string buscar(int init, int end, string num_a_buscar){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/hash.txt");
    string linea;
    string texto;
    int i = 0;
    while (i < 500){
        getline(archivo,linea);
        while (end = linea.find("-", init), end >=0){
            if(linea.substr(init, end - init) == num_a_buscar){
                init = end + 1;
                return linea.substr(init, end - init);
            }
            i++;
            getline(archivo,linea);
        }
        i++;
        getline(archivo,linea);
    }
    return "Fallido";
}

/*
int main(){
    generarHash();

    
    for(auto pair : MisCartas){
        int i = 0;
        cout << pair.first << " - " << pair.second << endl;
        }

    string num_a_buscar = "15";
    guardar();
    string s = buscar(0,0,num_a_buscar);
    cout << s << endl;
    

    return 0;
}
*/
