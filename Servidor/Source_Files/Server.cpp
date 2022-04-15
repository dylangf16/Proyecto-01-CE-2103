#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/Hashmap.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz_dinamica.cpp"
#include "/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/matriz.cpp"
 
using namespace std;
//int **puntero_matriz;
//string linea2;

/*
void mostrarMatriz(int **puntero_matriz, int nFilas, int nCol){
    cout << "Imprimiendo la matriz en memoria:" << endl;
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            cout << *(*(puntero_matriz+i)+j) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

string buscar(int **puntero_matriz, int nFilas, int nCol, int num, string resul){
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            int num_matrix = *(*(puntero_matriz+i)+j);
            if(num_matrix == num){
                resul = "True";
                return resul;
            }
        }
    }
    return "False";
}

void eliminar_memoria(int **puntero_matriz, int nFilas, int nCol){
    //Liberar la memoria utilizada en la matriz
    for (int i = 0; i < nFilas; i++){
        free(puntero_matriz[i]);
        puntero_matriz[i] = nullptr;
    }
    free(puntero_matriz);
    puntero_matriz = nullptr;
    cout << "memoria eliminada" << endl;
}

//Se reserva la matriz en memoria
string rellenarMatriz(int nFilas, int nCol, string num){
    ifstream archivo("/home/dylan16/Documents/Datos2/Proyecto01/Proyecto-01-CE-2103/Matriz/Source_Files/disco.txt");


    //Establece un valor a cada posición de la matris dinámica
    cout << sizeof(short int) * nCol *5<< endl;
    cout << sizeof(short int) * nFilas *5<< endl;
    puntero_matriz = (int**) malloc(sizeof(short int)*nCol*2); 
    for (int i = 0; i < nFilas; i++){
        int nFilas2 = nFilas;
        int nCol2 = nCol;
        puntero_matriz[i] = (int*) malloc(sizeof(short int)*nFilas*2);
    }
    for (int i = 0; i < nFilas; i++){
        for(int j = 0; j <nCol; j++){
            getline(archivo,linea2);
            *(*(puntero_matriz+i)+j) = std::stoi(linea2);
        }
    }
    
    //Obtiene la memoria usada por el programa utilizando lineas de comando
    int id = getpid();
    string string("pmap -p ");
    string.append(to_string(id));
    char const *pchar2 = string.c_str();
    cout << system(pchar2) << endl;
    string.append(" | tail -n 1 | awk '/[0-9]K/{print $2}'");
    char const *pchar = string.c_str();
    cout << "ID del programa: " << id << endl;
    int memoria_usada = system(pchar);
    mostrarMatriz(puntero_matriz, nFilas, nCol);


    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::string resul = buscar(puntero_matriz,nFilas,nCol,stoi(num),"False");
    cout << resul << endl;
    eliminar_memoria(puntero_matriz,nFilas,nCol);
    return resul;
}

*/

int main()
{
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }
 
    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
 
    bind(listening, (sockaddr*)&hint, sizeof(hint));
 
    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);
 
    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
 
    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
 
    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
 
    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 
    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        //cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        //cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
 
    // Close listening socket
    close(listening);
 
    // While loop: accept and echo message back to client
    char buf[4096];
 
    while (true)
    {
        memset(buf, 0, 4096);
        string command = "NULL";
        string val1 = "NULL";
        string val2 = "NULL";
        string val3 = "NULL";

        int init = 0;
        int end = 0;
 
        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }
        
        if (bytesReceived == 0)
        {
            //cout << "Client disconnected " << endl;
            break;
        }
        

        //Analizar y dividir string recibido
        std::string linea = string(buf,0,bytesReceived);
        int conteo = 0;
        while(end=linea.find("-", init), end >= 0){
            if (command == "NULL" & conteo == 0){
                command = linea.substr(init, end-init);
                init = end + 1;
            }
            if (val1 == "NULL" & conteo == 1){
                val1 = linea.substr(init, end-init);
                init = end + 1;
            }
            if (val2 == "NULL" & conteo == 2){
                val2 = linea.substr(init, end-init);
                init = end + 1;
            }
            if (val3 == "NULL" & conteo == 3){
                val3 = linea.substr(init, end-init);
                init = end + 1;
            }
            conteo +=1;
        }

        if(command == "IMG"){
            string num = buscar(0,0,val1);
            send(clientSocket, num.c_str(), num.size() + 1, 0);
        }

        if(command == "Matrix_mem"){
            string num = rellenarMatriz(stoi(val1),stoi(val2),val3);
            mostrar_matriz_disco(stoi(val1),stoi(val2));
            send(clientSocket, num.c_str(), num.size() + 1, 0);
        }

        if(command == "Start"){
            generarMatriz();
            generarHash();
            string num = "Terminado";
            send(clientSocket, num.c_str(), num.size() + 1, 0);
        }
        if(command == "Mix"){
            revolverMatriz();
            
            string num = "Terminado";
            send(clientSocket, num.c_str(), num.size() + 1, 0);
        }
          
    }
 
    // Close the socket
    close(clientSocket);
    main();
 
    return 0;
}
