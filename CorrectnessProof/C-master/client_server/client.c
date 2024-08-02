
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32                            
#define _WINSOCK_DEPRECATED_NO_WARNINGS  
                                         
#include <winsock2.h>
#define bzero(b, len) \
    (memset((b), '\0', (len)), (void)0) 
#define read(a, b, c) recv(a, b, c, 0)  
#define write(a, b, c) send(a, b, c, 0) 
#define close closesocket               
#else                                   
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#define MAX 80             
#define PORT 8080          
#define SA struct sockaddr 


void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;)
    {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
        {
            ;
        }
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0)
        {
            printf("Client Exit...\n");
            break;
        }
    }
}

#ifdef _WIN32

void cleanup() { WSACleanup(); }
#endif


int main()
{
#ifdef _WIN32
    
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0)
    {
        perror("WSA Startup error: \n");
        return 0;
    }

    atexit(cleanup);  
#endif

    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    {
        printf("Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
    {
        printf("connected to the server..\n");
    }

    
    func(sockfd);

    
    close(sockfd);
    return 0;
}
