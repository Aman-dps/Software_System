/*
======================================================================================
Name        : 34b.c
Author      : Aman Tiwari
Description : 
Write a program to create a concurrent server using pthreads.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

// Function executed by each client thread
void *handle_client(void *socket_desc) {
    int new_socket = *(int *)socket_desc;
    char buffer[1024] = {0};
    const char *message = "Hi, this is a message from server";

    // Read message from client
    read(new_socket, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);

    // Send reply to client
    send(new_socket, message, strlen(message), 0);

    close(new_socket);
    free(socket_desc);
    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept and handle multiple clients concurrently using threads
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0) {
            perror("accept");
            continue;
        }

        pthread_t thread_id;
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) != 0) {
            perror("pthread_create");
            free(new_sock);
        } else {
            pthread_detach(thread_id);  // Automatically reclaim thread resources
        }
    }

    close(server_fd);
    return 0;
}

/*
======================================================================================
OUTPUT:
--------------- Terminal 1 (Server) ---------------
aman-tiwari@aman-tiwari:~/Hands_on_list2$ gcc 34b.c -lpthread -o server
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./server
Server listening on port 8080...
Client: Hello from client
Client: Hello from client
Client: Hello from client

--------------- Terminal 2 (Client) ---------------
aman-tiwari@aman-tiwari:~/Hands_on_list2$ gcc 34b_client.c -o client
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./client
Hello message sent
Server response: Hi, this is a message from server
======================================================================================
*/
