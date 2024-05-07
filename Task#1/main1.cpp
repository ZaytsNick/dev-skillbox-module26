#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>
class Track
{
    std::string name;
    std::time_t t = std::time(nullptr);
    std::tm dateTrack = *std::localtime(&t);
    int timeIsOut;
    void write_info()
    {
        std::cout << "Name: " << name
                  << "\nDate track: " << std::put_time(&dateTrack, "%m-%d-%y")
                  << "\nTime will run out in " << timeIsOut << std::endl;
    }
    friend class Player;
    friend void createTrack(int quantity, std::vector<Track> &Tracks);
    // public:
    //     void createTrack(int quantity, std::vector<Track> Tracks)
    //     {
    //         srand(time(0));
    //         Track tmp_track;
    //         for (int i = 0; i < quantity; i++)
    //         {
    //             tmp_track.name = "track#" + std::to_string(2 + 1);
    //             tmp_track.dateTrack.tm_mday = rand() % 30;
    //             tmp_track.dateTrack.tm_mon = rand() % 12;
    //             tmp_track.dateTrack.tm_year = rand() % 2025 + 1930;
    //             tmp_track.timeIsOut = rand() % 300 + 60;
    //             Tracks.push_back(tmp_track);
    //         }
    //     }
};
class Player
{
    // friend class Track;
    std::vector<Track> playList;
    bool playTrack = false;

public:
    void addTrack(std::vector<Track> Tracks, int quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            playList.push_back(Tracks[i]);
        }
    }
    void play()
    {
        if (!playTrack)
        {
            std::cout << "Enter name track: ";
            std::string tmp;
            std::cin >> tmp;
            for (int i = 0; i < playList.size(); i++)
            {
                if (playList[i].name == tmp)
                {
                    playList[i].write_info();
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
            playList[rand() % playList.size()].write_info();
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
void createTrack(int quantity, std::vector<Track> &Tracks)
{
    srand(time(0));
    Track tmp_track;
    for (int i = 0; i < quantity; i++)
    {
        tmp_track.name = "track#" + std::to_string(i + 1);
        tmp_track.dateTrack.tm_mday = rand() % 30;
        tmp_track.dateTrack.tm_mon = rand() % 12;
        tmp_track.dateTrack.tm_year = rand() % 2025 + 1930;
        tmp_track.timeIsOut = rand() % 300 + 60;
        Tracks.push_back(tmp_track);
    }
}
int main()
{
    std::vector<Track> Tracks;
    createTrack(5, Tracks);
    Player player;
    player.addTrack(Tracks, Tracks.size());
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
