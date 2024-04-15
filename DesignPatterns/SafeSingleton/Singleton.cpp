#include <iostream>
#include <mutex>

class Singleton
{
private:
	Singleton()
	{
		// Private constructor to prevent instantiation
	}

	static Singleton *instancePtr;
	static std::mutex mutex;
	int data;

public:
	static Singleton &getInstance()
	{
		// Double-checked locking pattern for thread safety
		if (instancePtr == nullptr)
		{
			std::lock_guard<std::mutex> lock(mutex);
			if (instancePtr == nullptr)
			{
				instancePtr = new Singleton();
			}
		}

		return *instancePtr;
	}

	// Delete copy condstructor and assignment operator
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;

	void setData(int value)
	{
		data = value;
	}

	int getData() const
	{
		return data;
	}
};

// Initialize static members
Singleton *Singleton::instancePtr = nullptr;
std::mutex Singleton::mutex;

int main(void)
{
	// Get Singleton instance
	Singleton &singleton = Singleton::getInstance();

	// Use singleton instance
	singleton.setData(42);
	std::cout << "Data in Singleton instance: " << singleton.getData() << std::endl
			  << std::endl;

	// Try to instantiate another Singleton instance (won't compile due to deleted copy constructor)
	// Singleton singleton2; // This will cause a compilation error
	return 0;
}
