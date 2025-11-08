/*
========================================================================
Name        : 34a.c
Author      : AMAN TIWARI
Description : Write a program to create a concurrent server using fork.
========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *message = "Hi, this is a message from server";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (fork() == 0) {
            read(new_socket, buffer, sizeof(buffer));
            printf("Client: %s\n", buffer);
            send(new_socket, message, strlen(message), 0);
            close(new_socket);
            exit(0);
        }
        close(new_socket);
    }

    return 0;
}

/*
========================================================================
OUTPUT:
(base) amantiwari@Amans-MacBook-Air handson2$ gcc q34a.c -o server
(base) amantiwari@Amans-MacBook-Air handson2$ ./server
Client: Hello from client

(base) amantiwari@Amans-MacBook-Air handson2$ gcc client.c -o client
(base) amantiwari@Amans-MacBook-Air handson2$ ./client
Hello message sent
Server response: Hi, this is a message from server
========================================================================
*/
