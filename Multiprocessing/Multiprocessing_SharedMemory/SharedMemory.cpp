#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include <chrono>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <cstring>

#define MESSAGE_SIZE 256

using namespace boost::interprocess;

// Structure for shared data
struct SharedData {
    char message[MESSAGE_SIZE];
};

// Client function
void ClientFunction(shared_memory_object& sharedMemObj, std::mutex& mutex) {
    std::ofstream clientLog("client_log.txt", std::ios::out | std::ios::app);
    if (!clientLog.is_open()) {
        std::cout << "Error: Could not open client_log.txt for writing!" << std::endl;
        return;
    }

    mapped_region region(sharedMemObj, read_write);
    {
        std::lock_guard<std::mutex> lock(mutex);
        SharedData* sharedData = static_cast<SharedData*>(region.get_address());
        // Print the message to console
        std::cout << "Client: Received message: " << sharedData->message << std::endl;
        // Write message in text file
        clientLog << "Received message: " << sharedData->message << std::endl;
    }
}

// Server function
void ServerFunction(shared_memory_object& sharedMemObj, std::mutex& mutex) {
    std::ofstream serverLog("server_log.txt", std::ios::out | std::ios::app);
    if (!serverLog.is_open()) {
        std::cout << "Error: Could not open server_log.txt for writing!" << std::endl;
        return;
    }

    mapped_region region(sharedMemObj, read_write);
    {
        std::lock_guard<std::mutex> lock(mutex);
        SharedData* sharedData = static_cast<SharedData*>(region.get_address());
        std::strcpy(sharedData->message, "Hello from server!");
        // Print the message to console
        std::cout << "Server: Sent message: " << sharedData->message << std::endl;
        // Write message in text file
        serverLog << "Sent message: " << sharedData->message << std::endl;
    }
}

int main() {
    // Store the names for mutex and shared memory
    const char* mutexName = "mutex";
    const char* sharedMemName = "shared_memory";

    // Create shared memory and mutex
    shared_memory_object sharedMemObj(open_or_create, sharedMemName, read_write);
    sharedMemObj.truncate(sizeof(SharedData));
    std::mutex globalMutex;

    // Start server and client tasks asynchronously
    std::future<void> serverTask = std::async(std::launch::async, ServerFunction, std::ref(sharedMemObj), std::ref(globalMutex));
    std::future<void> clientTask = std::async(std::launch::async, ClientFunction, std::ref(sharedMemObj), std::ref(globalMutex));

    // Wait for both tasks to complete
    serverTask.get();
    clientTask.get();

    // Clean up resources
    shared_memory_object::remove(sharedMemName);
    named_mutex::remove(mutexName);

    return 0;
}
