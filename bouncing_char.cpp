#include <iostream>
#include <thread>
#include <chrono>

constexpr int MAX_TIME = 50;

void grid_2d(int i, int j)
{
    // grid values
    int max_i{i}, max_j{j};
    //int grid_size = max_i * max_j;

    int x{0}, y{0};
    int dir_x{1}, dir_y{1};

    while(true)
    {
        system("clear");
        // grid loop
        for(int i = 0; i < max_i; ++i)
        {
            for(int j = 0; j < max_j; ++j)
            {
                if(i == y && j == x) std::cout << "@ ";
                else std::cout << ". ";
            }
            std::cout << '\n';
        }

        // move pixel
        x += dir_x;
        y += dir_y;

        // bounce off walls
        if(x == 0 || x == max_i - 1) dir_x *= -1;
        if(y == 0 || y == max_j - 1) dir_y *= -1;

        // wait for/sleep_for
        std::this_thread::sleep_for(std::chrono::milliseconds(MAX_TIME));
    }

//    // values output
//    std::cout << "Max I: " << max_i << '\n'
//              << "Max J: " << max_j << '\n'
//              << "Total Grid size: " << grid_size << '\n';
}

int main() {
    int x, y;
    std::cout << "Enter x, y values: ";
    std::cin >> x >> y;

    grid_2d(x, y);    
    return 0;
}
