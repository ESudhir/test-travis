#include "../Headers/loginDialog.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int network_socket;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginDialog w;
    w.show();
        network_socket = socket(AF_INET, SOCK_STREAM, 0);       // Creating a client socket
        if (network_socket < 0)
            cout << "ERROR opening clientsocket\n";
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9000);
        server_address.sin_addr.s_addr = INADDR_ANY;
        int connect_socket = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));    // Connect to the server
        if (connect_socket == -1) {
            cout << "Error connecting socket\n";
            exit(1);
        } else {
            cout << "socket connected\n";
        }
    return a.exec();
}
