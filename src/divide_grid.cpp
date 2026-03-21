#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "ansi.hpp"

constexpr int MAX_TIME = 100;

void divide_grid(int x, int y)
{
    int max_x{x};
    int max_y{y};

    int time{0};
    
    while(true)
    {
        // add animation position       
        std::cout << ansi::move(10, 1);

        // outputs columns
        for(int y{0}; y != max_y; ++y)
        {
            // outputs rows
            for(int x{0}; x != max_x; ++x)
            {
                if((y - x) == time) 
                {
                    std::cout << "🔸";
                }
                else if((x - y) == time)
                {
                    std::cout << "🔸";
                }
                else if(x > y) 
                {
                    std::cout << "🟪";
                }
                else 
                {
                    std::cout << "🟨";
                }
            }
                std::cout << ansi::reset;           

            std::cout << '\n';
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(MAX_TIME));
        time = (time + 1) % max_x;
    }
}

int main() 
{
    int x, y;
    std::cout << "Enter x and y: ";
    std::cin >> x >> y;
    divide_grid(x, y);
    return 0;
}
