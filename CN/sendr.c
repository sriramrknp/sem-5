#include "gbn.h"

int main(int argc, char *argv[])
{
    int sockfd; /* socket file descriptor of the client            */
    int numRead;
    socklen_t socklen;     /* length of the socket structure sockaddr         */
    char buf[DATALEN * N]; /* buffer to send packets                       */
    struct hostent he;	 / structure for resolving names into IP addresses */
	FILE inputFile;
    / input file pointer * /
        struct sockaddr_in server;

    socklen = sizeof(struct sockaddr);


        if (argc != 4)
    {
        fprintf(stderr, "usage: sender <hostname> <port> <filename>\n");
        exit(-1);
    }

    
        if ((inputFile = fopen(argv[3], "rb")) == NULL)
    {
        perror("fopen");
        exit(-1);
    }

    
        if ((he = gethostbyname(argv[1])) == NULL)
    {
        perror("gethostbyname");
        exit(-1);
    }

    
        if ((sockfd = gbn_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        perror("gbn_socket");
        exit(-1);
    }

     memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_addr = *(struct in_addr *)he->h_addr;
    server.sin_port = htons(atoi(argv[2]));


        if (gbn_connect(sockfd, (struct sockaddr *)&server, socklen) == -1)
    {
        perror("gbn_connect");
        exit(-1);
    }

    
        while ((numRead = fread(buf, 1, DATALEN * N, inputFile)) > 0)
    {
        if (gbn_send(sockfd, buf, numRead, 0) == -1)
        {
            perror("gbn_send");
            exit(-1);
        }
    }


        if (gbn_close(sockfd) == -1)
    {
        perror("gbn_close");
        exit(-1);
    }


        if (fclose(inputFile) == EOF)
    {
        perror("fclose");
        exit(-1);
    }

    return (0);
}