#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <sstream>
int bytesReceived;
std::string str;


using namespace std;

string Cliente(string command, string num_a_buscar, string i, string j, string x)
{
    //	Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return "1";
    }

    //	Create a hint structure for the server we're connecting with
    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return "1";
    }

    //	While loop:
    char buf[4096];


    do {

        //Comando para solicitar imágen en hashmap y cargarla en interfaz
        if (command == "IMG")
        {
        string userInput = command + "-" + num_a_buscar + "-" + "NULL";
        cout << userInput << endl;

        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }
        }

        //Comando para revisar matris en memoria y revisar si numero solicitado está en memoria
        //[i][j] = tamaño de matris en memoria  // x = num a buscar
        if (command == "Matrix_mem")
        {
        string userInput = command + "-" + i + "-" + j + "-" + x + "-" + "NULL";

        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }
        }

        //Comando para iniciar el juego, genera primera matris aleatoria y hashmap de las cartas y su imágenes
        if (command == "Start")
        {
        string userInput = command + "-" + "NULL";

        int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
            continue;
        }
        }

        //		Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            str = string(buf,bytesReceived);
        }
        break;

    } while(true);

    //	Close the socket
    close(sock);

    return str;
}