#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>

class Track
{
    std::string name = "unnamed";
    std::tm dateTrack;
    int timeIsOut;

    friend class Player;
};

class Player
{
};

int main()
{
}