#include <iostream>
#include <fstream>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>

#define COMM_PORT 8888

class Observer
{
public:
    virtual void update(const std::string &message) = 0;
};

class ServerObserver : public Observer
{
private:
    int clientSocket;
    std::ofstream outputFile;

public:
    ServerObserver(int socket, const std::string &filename) : clientSocket(socket)
    {
        outputFile.open(filename, std::ios::app);
    }

    int getClientSocket() const
    {
        return clientSocket;
    }

    void update(const std::string &message) override
    {
        std::istringstream iss(message);
        std::string line;
        while (std::getline(iss, line))
        {
            sendMessage(line);
            outputFile << "Received from client: " << line << std::endl;
        }
    }

    void sendMessage(const std::string &message)
    {
        send(clientSocket, message.c_str(), message.size(), 0);
    }
};

class Server
{
private:
    int serverSocket;
    std::string filename;
    std::thread acceptThread;

public:
    Server(int port, const std::string &logFilename) : filename(logFilename)
    {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == -1)
        {
            std::cerr << "Error: Could not create socket\n";
            return;
        }

        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(port);

        if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        {
            std::cerr << "Error: Bind failed. Port might be in use or permission denied.\n";
            return;
        }

        listen(serverSocket, 5);
        std::cout << "Server listening on port " << port << std::endl;

        acceptThread = std::thread(&Server::acceptClients, this);
    }

    ~Server()
    {
        if (acceptThread.joinable())
        {
            acceptThread.join();
        }
        close(serverSocket);
    }

    void acceptClients()
    {
        while (true)
        {
            int clientSocket = accept(serverSocket, NULL, NULL);
            if (clientSocket < 0)
            {
                std::cerr << "Error: Accept failed\n";
                continue;
            }

            std::cout << "New client connected" << std::endl;
            ServerObserver *observer = new ServerObserver(clientSocket, filename);
            std::thread clientThread([observer]()
                                     {
                while (true) {
                    char buffer[1024] = {0};
                    int valread = recv(observer->getClientSocket(), buffer, 1024, 0);
                    if (valread <= 0) {
                        std::cout << "Client disconnected" << std::endl;
                        delete observer;
                        return;
                    }
                    std::string message(buffer, valread); // Use valread to create string from received data only
                    observer->update(message);
                } });
            clientThread.detach();
        }
    }
};

class ClientObserver : public Observer
{
private:
    int serverSocket;
    std::ofstream outputFile;

public:
    ClientObserver(int socket, const std::string &filename) : serverSocket(socket)
    {
        outputFile.open(filename, std::ios::app);
    }

    void sendDataToServer(const std::string &message)
    {
        send(serverSocket, message.c_str(), message.size(), 0);
    }

    void update(const std::string &message) override
    {
        std::istringstream iss(message);
        std::string line;
        while (std::getline(iss, line))
        {
            std::cout << "Message sent to server: " << line << std::endl;
            outputFile << "Message sent to server: " << line << std::endl;
        }
    }
};

int main()
{
    // Server initialization
    Server server(COMM_PORT, "server_log.txt");

    // Client initialization
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        std::cerr << "Error: Could not create socket\n";
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(COMM_PORT);                     // Server port
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // Server IP address

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        std::cerr << "Error: Connection failed\n";
        return -1;
    }

    ClientObserver observer(clientSocket, "client_log.txt");

    // Simulate sending messages to the server
    std::thread sendThread([&observer]()
                           {
        while (true) {
            std::string message;
            std::cout << "Enter message to send to server (or type 'exit' to quit): ";
            std::getline(std::cin, message);
            if (message == "exit") {
                break;
            }
            observer.sendDataToServer(message);
        } });

    // Simulate receiving messages from the server
    char buffer[1024] = {0};
    while (true)
    {
        int valread = recv(clientSocket, buffer, 1024, 0);
        if (valread <= 0)
        {
            std::cerr << "Error: Server disconnected\n";
            break;
        }
        std::string message(buffer, valread); // Use valread to create string from received data only
        observer.update(message);
    }

    sendThread.join();   // Wait for send thread to finish
    close(clientSocket); // Close client socket

    return 0;
}
