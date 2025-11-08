/*
======================================================================================
Name        : 33b.c
Author      : Aman Tiwari
Description : 
Write a program to communicate between two machines using socket.
======================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Configure server address
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send message to server
    write(sockfd, "Hello from client", 17);

    // Read response from server
    int n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("Server says: %s\n", buffer);

    close(sockfd);
    return 0;
}

/*
======================================================================================
OUTPUT:
--------------- Terminal 1 (Server) ---------------
aman-tiwari@aman-tiwari:~/Hands_on_list2$ gcc 33a.c -o server
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./server
Server listening on port 8888...
Received: Hello from client

--------------- Terminal 2 (Client) ---------------
aman-tiwari@aman-tiwari:~/Hands_on_list2$ gcc 33b.c -o client
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./client
Server says: Message received
======================================================================================
*/
