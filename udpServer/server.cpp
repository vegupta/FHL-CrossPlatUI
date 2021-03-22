#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8088
#define MAXLINE 1024
int main() {
	std::cout << "Hello World!";

	// create a socket
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    	if(socket_fd < 0) {
    		perror("socket creation failed");
    		exit(EXIT_FAILURE);
    	}
    	std::cout << "Socket created" << std::endl;
    	
    	
    	//Bind the socket
    	//struct sockaddr_in {
              // sa_family_t    sin_family; /* address family: AF_INET */
              // in_port_t      sin_port;   /* port in network byte order */
             //  struct in_addr sin_addr;   /* internet address */
           //};
    	struct sockaddr_in socket_server_address {
    		AF_INET,
    		PORT,
    		inet_addr("127.0.0.1")
    	};
    	int socket_bind = bind(socket_fd, (const struct sockaddr *) &socket_server_address, 
                          sizeof(socket_server_address));
        if(socket_bind < 0) {
        	perror("bind failed");
        	exit(EXIT_FAILURE);
        }
        std::cout << "Socket Binding done" << std::endl;
        
        struct sockaddr_in client_address;
        memset(&client_address, 0, sizeof(client_address));
        socklen_t client_address_len = sizeof(client_address);
        char buffer[MAXLINE];
        ssize_t size = recvfrom(socket_fd, (char *)buffer, MAXLINE, MSG_WAITALL,
                 ( struct sockaddr *) &client_address, &client_address_len);
        
        buffer[size] = '\0';
	std::cout << " Value received from client " << buffer << std::endl;

        const char *hello = "Hello from server";    
        ssize_t sent_len = sendto(socket_fd, (const char *)hello, strlen(hello),
        MSG_CONFIRM, (const struct sockaddr *) &client_address, sizeof(client_address));
            
    	std::cout << "Hello Value sent to client" << hello << std::endl;   
    
	return 0;
}
