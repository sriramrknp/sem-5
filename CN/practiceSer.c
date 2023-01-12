//server
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    int sockd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockd < 0)
        exit(1);

    char data[100] = "Hello!, from server";

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9001);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(sockd, 1);

    int clientSocket = accept(sockd, NULL, NULL);
    send(clientSocket, data, sizeof(data), 0);
}