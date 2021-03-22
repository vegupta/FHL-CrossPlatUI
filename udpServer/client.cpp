#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080 
#define MAXLINE 1024
int main() {
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    	if(socket_fd < 0) {
    		perror("socket creation failed");
    		exit(EXIT_FAILURE);
    	}
    	std::cout << "Socket created" << std::endl;
    	
    	struct sockaddr_in socket_server_address {
    		AF_INET,
    		PORT,
    		inet_addr("127.0.0.1")
    	};
    	
        const char *hello = "Hello from client";    
        ssize_t sent_len = sendto(socket_fd, (const char *)hello, strlen(hello),
        MSG_CONFIRM, (const struct sockaddr *) &socket_server_address, sizeof(socket_server_address));
        

        char buffer[MAXLINE];
        socklen_t len;
        ssize_t size = recvfrom(socket_fd, (char *)buffer, MAXLINE, MSG_WAITALL,
                 ( struct sockaddr *) &socket_server_address, &len);
        
        buffer[size] = '\0';
	std::cout << " Value received from server " << buffer << std::endl;           	    		close(socket_fd);
	return 0;
}
