#include <iostream>
#include <thread>
#include <mutex>

// Extern variable shared between threads
int sharedVariable = 0;

// Mutex to protect sharedVariable
std::mutex mtx;

// Function for the first thread
void threadFunction1() {
    for (int i = 0; i < 10; ++i) {
        // Lock the mutex before accessing sharedVariable
        mtx.lock();

        // Read the sharedVariable
        int value = sharedVariable;

        // Modify the sharedVariable
        value += 1;
        sharedVariable = value;

        // Print the modified sharedVariable
        std::cout << "Thread 1: Shared variable = " << sharedVariable << std::endl;

        // Unlock the mutex after finishing access
        mtx.unlock();

        // Sleep for a short time to simulate some work being done
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Function for the second thread
void threadFunction2() {
    for (int i = 0; i < 10; ++i) {
        // Lock the mutex before accessing sharedVariable
        mtx.lock();

        // Read the sharedVariable
        int value = sharedVariable;

        // Modify the sharedVariable
        value -= 1;
        sharedVariable = value;

        // Print the modified sharedVariable
        std::cout << "Thread 2: Shared variable = " << sharedVariable << std::endl;

        // Unlock the mutex after finishing access
        mtx.unlock();

        // Sleep for a short time to simulate some work being done
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    // Create two threads
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);

    // Join the threads with the main thread
    t1.join();
    t2.join();

    return 0;
}
