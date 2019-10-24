//
//  main.c
//  Website-CScript
//
//  Created by Paige Lee on 10/1/19.
//  Copyright © 2019 Paige Lee. All rights reserved.
//
#include <stdio.h>
#include <sys/socket.h> //For Sockets
#include <stdlib.h>
#include <netinet/in.h> //For the AF_INET (Address Family)
#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    char pszRequest[100]={0};
    
    char pszResourcePath[]="signup";
    
    char pszHostAddress[]="www.facebook.com";
    
    sprintf(pszRequest, "GET /signup \nHost: %s\r\nContent-Type: text/plain\r\n\r\n", pszResourcePath, pszHostAddress);
    
    printf("Created Get Request is below:\n\n\n");
    
    printf("%s", pszRequest);
    
    return 0;
}
