//
//  main.c
//  Facebook_Socket
//
//  Created by Paige Lee on 10/8/19.
//  Copyright © 2019 Paige Lee. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <string.h>

int main(){
    // creating socket
    int client_socket;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    int connection_status= connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1){
        printf("There was an error making a connection to the remote socket \n");
    }
    char server_response[256];
    recv(client_socket, &server_response, sizeof(server_response), 0);
    
    printf("The server sent the data. %s\n", server_response);
    
    close(client_socket);
    return 0;
    
}
