/*
========================================================================
Name        : 33a.c
Author      : AMAN TIWARI
Description : 
Write a program to communicate between two machines using socket.
========================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server, client;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 5);

    socklen_t clilen = sizeof(client);
    newsockfd = accept(sockfd, (struct sockaddr*)&client, &clilen);

    int n = read(newsockfd, buffer, sizeof(buffer)-1);
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    write(newsockfd, "Message received", 17);

    close(newsockfd);
    close(sockfd);
    return 0;
}

/*
========================================================================
OUTPUT:

aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/33$ gcc 33a.c -o a
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/33$ ./a
Received: Hello from client
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/33$ 

aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/33$ gcc 33b.c -o b
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/33$ ./b
Server says: Message received
========================================================================
*/
