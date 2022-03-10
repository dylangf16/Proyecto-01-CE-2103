#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main(){
    //Creación del Socket
    int listening = socket(AF_INET, SOCK_STREAM,0);
    if (listening == -1)
    {
        cerr << "Error de socket";
        return -1;
    }
    // Conectar el socket a una IP / Port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1)
    {
        cerr << "No se puede conectar al IP/PORT";
        return -2;
    }

    //Socket que escucha
    if(listen(listening, SOMAXCONN) == -1)
    {
        cerr << "No se detecta nada";
        return -3;
    }

    //Aceptar llamadas
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host [NI_MAXHOST];
    char svc [NI_MAXSERV];
    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    if(clientSocket == -1)
    {
        cerr << "Error al conectar el cliente";
        return -4;
    }

    //Cerrar el socket
    close(listening);
    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);
    if(result){
        cout << host << "Conectando. . . ." << svc << endl;
    } else{
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << "Conectado en: " << ntohs(client.sin_port) << endl;
    }

    //Mientras se reciben mensajes, responder
    char buf[4096];
    while(true){
        //Limpiar el buffer
        memset(buf, 0, 4096);
        int bytesRecv = recv(clientSocket, buf, 4096,0);

        //Esperar un mensaje
        if (bytesRecv == -1){
            cerr << "Hubo un error de conexión" << endl;
            break;
        }

        if (bytesRecv == 0){
            cout << "El cliente se desconectó" << endl;
            break;
        }

        //Mostrar el mensaje
        cout << "Recieved: " << string(buf,0,bytesRecv) << endl;

        //Reenviar el mensaje
        send(clientSocket, buf, bytesRecv +1, 0);

    }

    //Cerrar el Socket
    close(clientSocket);
    return 0;
    }
