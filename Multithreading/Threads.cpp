#include <iostream>
#include <thread>
#include <mutex>

// Exterm variable shared between threads
extern int sharedVar;

// Mutex for sync
std::mutex mtx;

// Function to be executed by threads
void task(int threadID)
{
    // Loop to perform operations on the shared variable
    for(int i = 0; i < 5; ++i)
    {
        // Lock the mutex before accessing the shared variable
        mtx.lock();

        // Read the shared variable
        int value = sharedVar;

        // Modify the shared variable
        value += threadID;
        sharedVar = value;

        // Print the modified value
        std::cout << "Thread " << threadID << ": Shared variable = " << sharedVar << std::endl;

        // Unlock the mutex after accessing the shared variable
        mtx.unlock();

        // Simulate some background stuff
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}