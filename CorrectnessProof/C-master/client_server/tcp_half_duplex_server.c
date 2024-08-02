

#ifdef _WIN32
#define bzero(b, len) \
    (memset((b), '\0', (len)), (void)0) 
#define close _close
#include <Ws2tcpip.h>
#include <io.h>
#include <winsock2.h>
#else
#include <netdb.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <unistd.h>
#endif

#include <stdint.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define PORT 8100  


void error()
{
    perror("Socket Creation Failed");
    exit(EXIT_FAILURE);
}


int main()
{
    
    uint32_t sockfd,
        conn;  
    char server_msg[10000],
        client_msg[10000];  
                            
    struct sockaddr_in server_addr,
        client_addr;  
                      
                      

    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        error();  
                  
    }

    
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;    
    server_addr.sin_port = htons(PORT);  
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("Server is running...\n");

    
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error();  
    }

    
    listen(sockfd, 5);

    printf("Server is listening...\n");

    
    conn = accept(sockfd, (struct sockaddr *)NULL, NULL);

    printf("Server is connected...\n");

    
    while (1)
    {
        bzero(&server_msg, sizeof(server_msg));
        bzero(&client_msg, sizeof(client_msg));

        
        printf("\nEnter message here: ");
        fgets(server_msg, 10000, stdin);
        send(conn, server_msg, strlen(server_msg) + 1, 0);

        
        recv(conn, client_msg, sizeof(client_msg), 0);
        printf("\nClient Message: %s\n", client_msg);
    }

    
    close(sockfd);
    printf("Server is offline...\n");
    return 0;
}
