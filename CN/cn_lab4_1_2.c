// CS20B1107, SRIRAM REDDY CHEERLA
// server

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h> 
#include <sys/types.h>

int main()
{
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);

    int bytes_read;
    int size = 10;
    char *string;
    string = (char *)malloc(size);

    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9001);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(servSockD, (struct sockaddr *)&serverAddr,sizeof(serverAddr));
    listen(servSockD, 5);

    int clientSocket = accept(servSockD, NULL, NULL);

    bytes_read = getline(&string, &size, stdin);
    send(clientSocket, string, sizeof(string), 0);
}
