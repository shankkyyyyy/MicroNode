#pragma once

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1028

typedef struct ServerConfig {
    int port;
    int server_fd;
    uint32_t addrlen;
    struct sockaddr_in address;
}ServerConfig;

enum NetworkingError{
    NETWORKING_ERROR = -1,
};

int init_networking(ServerConfig *Config)
{
    Config->addrlen = sizeof(Config->address);
    Config->server_fd = socket(AF_INET, SOCK_STREAM, 0);


    if (Config->server_fd == NETWORKING_ERROR) {
        perror("socket");
        return EXIT_FAILURE;
    }

    Config->address.sin_family = AF_INET;
    Config->address.sin_port = htons(Config->port);
    Config->address.sin_addr.s_addr = INADDR_ANY;
    // change -1 to a enum type
    if (bind(Config->server_fd, (struct sockaddr *)&Config->address, Config->addrlen) == NETWORKING_ERROR) {
        perror("bind");
        return EXIT_FAILURE;
    }
    // change 0 to a enum type // debug
    if(listen(Config->server_fd,5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    printf("Listening on port %d...\n", Config->port);

    return EXIT_SUCCESS;
}

int handle_client(ServerConfig *Config)
{
    int client_fd = accept(Config->server_fd,(struct sockaddr*)&Config->address,(socklen_t *)&Config->addrlen);
    if (client_fd < 0)
        {
            perror("accept");
            return EXIT_FAILURE;
        }

    char temp_buffer[BUFFER_SIZE];
    memset(temp_buffer,0,BUFFER_SIZE);
    int ValueRead = recv(client_fd,temp_buffer,BUFFER_SIZE,0);
    if (ValueRead < 0 ) {perror("recv"); return EXIT_FAILURE;}

    printf("%s",temp_buffer);
    return EXIT_SUCCESS;
}
