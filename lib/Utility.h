#pragma once

#include <iostream>
#include <vector>

#define NUM_OF_CHARS 22

class Utility
{
public:
    static double Average(const std::vector<int> &nums);
    static void Hello(const std::string &message);
    static void PrintCharacter(char character);
};