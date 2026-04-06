#include "conway.hpp"
#include <chrono>
#include <thread>

int main()
{
    Conway grid(20, 20); 
    grid.generate_random();

    while(true)
    {
        grid.display();
        grid.update();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    return 0;
}
