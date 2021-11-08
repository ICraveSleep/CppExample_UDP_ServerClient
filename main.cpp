// https://www.bogotobogo.com/cplusplus/sockets_server_client.php
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstring>


int main(){
    int PORT = 22002;
    int MAXLINE = 10000;
    int buff_size = 64;
    char buffer[buff_size]{};
    char array[buff_size]{};
    // char *message = "Hello Client";
    int listenfd;
    int len;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));
    // Create a UDP Socket
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);        
    // servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET; 
   
    // bind server address to socket descriptor
    bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
       
    //receive the datagram
    len = sizeof(cliaddr);
    
    socklen_t s_len = len;
    // bzero(buffer, buff_size);

    while(1){
        int n = recvfrom(listenfd, buffer, sizeof(buffer),
            0, (struct sockaddr*)&cliaddr,&s_len); //receive message from server
    buffer[n] = '\0';
    std::cout << "N is: " << n << std::endl;
    // for (int i = 0; i < buff_size; i++){
    for (int i = 0; i < 5; i++){
        // array[i] = ntohl(buffer[i]) ;
        // std::cout << "array[" << i << "]=" << +buffer[i] << " ";
        // // std::cout << "array[" << i << "] = " << +array[i];
        // if(i % 10 == 1 && i != 1){
        //     std::cout << std::endl;
        // }
        uint8_t a = uint8_t(buffer[i]);
        std::bitset<8> x(a);
        std::cout << x << std::endl;
        
     }
    // puts(buffer);
    // printf("Here is the message: %i\n",buffer[0]);
    
    float f;
    char b[] = {buffer[0], buffer[1], buffer[2], buffer[3]};
    memcpy(&f, &b, sizeof(f));
    std::cout << "Constructed float: " << f << " Pole angle [rad]" << std::endl;
    // send the response
    // sendto(listenfd, message, MAXLINE, 0,
    //       (struct sockaddr*)&cliaddr, sizeof(cliaddr));

    std::cout << "Got message" << std::endl;
    }
    
}