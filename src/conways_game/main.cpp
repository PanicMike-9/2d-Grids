#include "conway.hpp"
#include <chrono>
#include <thread>

int main()
{
    Conway grid(40, 40); 
    grid.generate_random();

    while(true)
    {
        grid.display();
        grid.update();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    return 0;
}
