/*
======================================================================================
Name        : 34b_client.c
Author      : Aman Tiwari
Description : 
Write a client program to communicate with a concurrent (multithreaded) server.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    // Send message to server
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Read server response
    read(sock, buffer, sizeof(buffer));
    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}

/*
======================================================================================
OUTPUT:
--------------- Terminal 1 (Server) ---------------
aman-tiwari@aman-tiwari:~/Hands_on_list2$ gcc 34b.c -lpthread -o server
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./server
Client: Hello from client

--------------- Terminal 2 (Client) ---------------
aman-tiwari@aman-tiwari:~/Hands_on_list2$ gcc 34b_client.c -o client
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./client
Hello message sent
Server response: Hi, this is a message from server
======================================================================================
*/
