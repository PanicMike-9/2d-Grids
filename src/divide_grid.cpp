#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

constexpr int MAX_TIME = 100;

void divide_grid(int x, int y)
{
    int max_x{x};
    int max_y{y};
    
    int sum_x{0};
    int sum_y{0};

    int time{0};
    
    while(true)
    {
        // add smooth transition        
        std::cout << "\033[H\033[J" << std::flush;

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
                //sum_x++;
            }
                std::cout << "\033[0m" << std::flush;
            
            std::cout << '\n';
            //sum_y++;
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(MAX_TIME));
        time = (time + 1) % max_x;
    }
    
    // output grid value
    std::cout << "total row(x): " << sum_x << '\n'
              << "total col(y): " << sum_y << '\n'
              << "initial rows(x): " << sum_x / sum_y << '\n';
}

int main() 
{
    int x, y;
    std::cout << "Enter x and y: ";
    std::cin >> x >> y;
    divide_grid(x, y);
    return 0;
}
