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

// Define a structure for the shared data
struct SharedData
{
    char message[MESSAGE_SIZE]; // Buffer for shared message
};

// Function for the client-side operation
void ClientFunction(shared_memory_object &sharedMemObj, std::mutex &mutex)
{
    // Open a log file for client operations
    std::ofstream clientLog("client_log.txt", std::ios::out | std::ios::app);
    if (!clientLog.is_open())
    {
        std::cout << "Error: Could not open client_log.txt for writing!" << std::endl;
        return;
    }

    // Create a mapped region to access shared memory
    mapped_region region(sharedMemObj, read_write);

    {
        // Lock the mutex to ensure safe access to shared memory
        std::lock_guard<std::mutex> lock(mutex);

        // Cast the mapped region's address to a pointer of SharedData
        SharedData *sharedData = static_cast<SharedData *>(region.get_address());

        // Output the message received from shared memory to console and log
        std::cout << "Client: Received message: " << sharedData->message << std::endl;
        clientLog << "Received message: " << sharedData->message << std::endl;
    }
}

// Function for the server-side operation
void ServerFunction(shared_memory_object &sharedMemObj, std::mutex &mutex)
{
    // Open a log file for server operations
    std::ofstream serverLog("server_log.txt", std::ios::out | std::ios::app);
    if (!serverLog.is_open())
    {
        std::cout << "Error: Could not open server_log.txt for writing!" << std::endl;
        return;
    }

    // Create a mapped region to access shared memory
    mapped_region region(sharedMemObj, read_write);

    {
        // Lock the mutex to ensure safe access to shared memory
        std::lock_guard<std::mutex> lock(mutex);

        // Cast the mapped region's address to a pointer of SharedData
        SharedData *sharedData = static_cast<SharedData *>(region.get_address());

        // Write a message into shared memory and log the operation
        std::strcpy(sharedData->message, "Hello World!");
        std::cout << "Server: Sent message: " << sharedData->message << std::endl;
        serverLog << "Sent message: " << sharedData->message << std::endl;
    }
}

int main()
{
    // Define shared memory and mutex names
    const char *mutexName = "mutex";
    const char *sharedMemName = "shared_memory";

    // Create or open shared memory with read-write access
    shared_memory_object sharedMemObj(open_or_create, sharedMemName, read_write);

    // Set the size of shared memory to accommodate the SharedData structure
    sharedMemObj.truncate(sizeof(SharedData));

    // Create a global mutex for synchronization
    std::mutex globalMutex;

    // Start asynchronous server and client tasks
    std::future<void> serverTask = std::async(std::launch::async, ServerFunction, std::ref(sharedMemObj), std::ref(globalMutex));
    std::future<void> clientTask = std::async(std::launch::async, ClientFunction, std::ref(sharedMemObj), std::ref(globalMutex));

    // Wait for both tasks to complete before proceeding
    serverTask.get();
    clientTask.get();

    // Clean up shared memory and mutex resources
    shared_memory_object::remove(sharedMemName);
    named_mutex::remove(mutexName);

    return 0;
}
