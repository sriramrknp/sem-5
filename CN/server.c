#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    // socket() Bind() listen()
    // accept() read() write() close()

    // int sockFd = socket(int domain, int type, int protocol);
    // domain - address protocol, AF_INET = Ipv4
    // type SOCK_STREAM - TCP/IP, SOCK_DCRAM - UDP
    // protocol 0
    // bind() - socket created and exits in namespace, but no address assigns to it
    //       bind assigns to it
    // int bind(int socFd, struct sockaddr *addr, socklen_t addrlen);
    // struct sockaddr {
    //    sa_family_t sa_family;
    //    char sa_data[14];
    // }
    // int listen(int sockFd, int backlog);
    // mark sockfd as passive socket that is, it will listen from only this
    // backlog is number of connections
    // newsockfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
    // int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    // 0 - success, -1 failure
    // int read(newsockfd, buffer, buffer_size);
    // buffer is the message we sending(string)
    // int write(newsockfd, buffer, buffer_size);
    
    
}