#include "Utility.h"

double Utility::Average(const std::vector<int> &nums)
{
    int sum = 0;
    int size = nums.size();     // determinam lungimea vectorului
    
    for(int i = 0; i < size; ++i)
    {
        sum += nums[i];
    }

    return static_cast<double>(sum) / size;
}

void Utility::Hello(const std::string & message)
{
    std::cout << "Message from Utility class : " << message << std::endl;
}

void Utility::PrintCharacter(char character)
{
    for (int i = 0; i < NUM_OF_CHARS; ++i)
    {
        std::cout << character;
    }
    std::cout << std::endl;
}