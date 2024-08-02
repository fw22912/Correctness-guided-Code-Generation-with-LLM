

#ifdef _WIN32
#define bzero(b, len) \
    (memset((b), '\0', (len)), (void)0) 
#define close _close
#include <Ws2tcpip.h>
#include <io.h>
#include <winsock2.h>  
#else
#include <arpa/inet.h>  
#include <netdb.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <unistd.h>
#endif
#include <errno.h>   
#include <stdint.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define PORT 10000  


void error()
{
    perror("Socket Creation Failed");
    exit(EXIT_FAILURE);
}


int main()
{
    
    uint32_t
        sockfd;  
    char recv_msg[1024],
        success_message[] =
            "Command Executed Successfully!\n";  
                                                 
                                                 
                                                 

    struct sockaddr_in server_addr,
        client_addr;  
                      
                      
    socklen_t clientLength = sizeof(client_addr);  

    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        error();
    }

    
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error();  
    }

    printf("Server is Connected Successfully...\n");

    
    while (1)
    {
        bzero(recv_msg, sizeof(recv_msg));
        recvfrom(sockfd, recv_msg, sizeof(recv_msg), 0,
                 (struct sockaddr *)&client_addr, &clientLength);
        printf("Command Output: \n");
        system(recv_msg);
        printf("Command Executed\n");
        sendto(sockfd, success_message, sizeof(success_message), 0,
               (struct sockaddr *)&client_addr, clientLength);
    }

    
    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}
