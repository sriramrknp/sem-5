// client

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>

int main()
{
    int sockd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9001);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStats = connect(sockd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
 
    if(connectStats < 0){
        exit(1);
    }
    else{
        char data[100];
        recv(sockd, data, sizeof(data), 0);
        printf("data %s", data);
    }
}