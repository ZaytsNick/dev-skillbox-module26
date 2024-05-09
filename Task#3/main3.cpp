
#include <iostream>
#include <vector>

class Window
{
    int coord[2] = {2, 3};
    int height = 20;
    int weight = 15;

public:
    void move()
    {
        std::cout << "Enter new coordinates: ";
        std::cin >> coord[0] >> coord[1];
    }
    void resize()
    {
        std::cout << "Enter new height and weight: ";
        std::cin >> height >> weight;
    }
    friend class Display;
};
class Display
{
    bool disp[50][80];

public:
    void display(Window wind)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 80; j++)
            {
                if (j >= wind.coord[1] && j <= wind.coord[1] + wind.weight && i >= wind.coord[0] && i <= wind.coord[0] + wind.height)
                    std::cout << '1';
                else
                    std::cout << '0';
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Display disp;
    Window window;
    std::string command;
    while (command != "close")
    {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "move")
            window.move();
        else if (command == "resize")
            window.resize();
        else if (command == "display")
            disp.display(window);
    }
}