#include <iostream>
#include <string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

string getLocalIPAddress() {
    // Initialize Winsock
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cerr << "WSAStartup failed with error: " << result << endl;
        return "";
    }

    // Get hostname
    char hostname[256];
    DWORD hostname_size = sizeof(hostname);
    if (gethostname(hostname, hostname_size) == SOCKET_ERROR) {
        cerr << "Failed to get hostname: " << WSAGetLastError() << endl;
        WSACleanup();
        return "";
    }

    // Get host information by hostname
    struct hostent *host_entry;
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        cerr << "Failed to get host information for " << hostname << ": " << WSACetLastError() << endl;
        WSACleanup();
        return "";
    }

    // Loop through IP addresses and return the first one
    for (int i = 0; host_entry->h_addr_list[i] != 0; ++i) {
        struct in_addr *address_ptr = (struct in_addr *)host_entry->h_addr_list[i];
        char address[INET_ADDRSTRLEN];

        // Use inet_ntoa to convert IP address to string (be aware of limitations)
        strcpy_s(address, sizeof(address), inet_ntoa(*address_ptr));

        WSACleanup();
        return string(address); // Return the first IP address found
    }

    // If no IP addresses found
    WSACleanup();
    return "";
}

int main() {
    string ipAddress = getLocalIPAddress();
    if (ipAddress.empty()) {
        cerr << "Failed to get local IP address." << endl;
    } else {
        wstring message = L"Thank you! Your local IP address is: " + wstring(ipAddress.begin(), ipAddress.end());
        MessageBoxW(NULL, message.c_str(), L"HI", 0x00000000L);
    }
    return 0;
}
