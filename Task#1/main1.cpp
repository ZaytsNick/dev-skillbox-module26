#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>

class Track
{
    friend class Player;

public:
    std::string name;
    std::tm dateTrack;
    int timeIsOut;
    void write_info()
    {
        std::cout << "Name: " << name
                  << "\nDate track" << std::put_time(&dateTrack, "%m-%d-%y")
                  << "\nTime will run out in " << timeIsOut << std::endl;
    }
};

class Player
{

    std::vector<Track> Tracks;
    bool playTrack = false;

public:
    void addTrack(int quantity)
    {
        std::time_t t = std::time(nullptr);
        std::tm local = *std::localtime(&t);
        srand(time(0));
        for (int i = 0; i < quantity; i++)
        {
            local.tm_mday = rand() % 30;
            local.tm_mon = rand() % 12;
            local.tm_year = rand() % 2025 + 1930;
            std::string aaa = "track#" + std::to_string(i + 1);
            Track temp_track = {aaa, local, rand() % 300 + 60};
            Tracks.push_back(temp_track);
        }
    }
    void play()
    {
        if (!playTrack)
        {
            std::cout << "Enter name track: ";
            std::string tmp;
            std::cin >> tmp;
            for (int i = 0; i < Tracks.size(); i++)
            {
                if (Tracks[i].name == tmp)
                {
                    Tracks[i].write_info();
                    playTrack = true;
                    break;
                }
            }
        }
    }
    void pause()
    {
        if (playTrack)
        {
            playTrack = false;
            std::cout << "Track pause" << std::endl;
        }
    }
    void next()
    {
        if (playTrack)
        {
            srand(time(0));
            Tracks[rand() % 10].write_info();
        }
    }
    void stop()
    {
        if (playTrack)
        {
            playTrack = false;
            std::cout << "Track stop" << std::endl;
        }
    }
};

int main()
{
    Player player;
    player.addTrack(10);
    std::string command;
    while (command != "exit")
    {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "play")
            player.play();
        else if (command == "pause")
            player.pause();
        else if (command == "next")
            player.next();
        else if (command == "stop")
            player.stop();
    }
}