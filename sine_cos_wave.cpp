#include <iostream>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>

constexpr double PI = 3.14159265358979323846;

void sin_cos_helix()
{
    double input_interval{0.0};

    std::cout << "Enter interval: ";

    // user intput validation
    while(!(std::cin >> input_interval)) 
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please input a valid number: ";
    }

    const int width = 40;
    const double interval = input_interval;

    // smaller the degress += value, longer the curve
    // forward curve
    for(double degrees = 0; degrees <= 360; degrees += interval)
    {
        double radians = degrees * (PI / 180.0);

        double sine_val = std::sin(radians);
        double cos_val = std::cos(radians);

        int pos_1 = static_cast<int>((sine_val + 1) * (width / 2));
        int pos_2 = static_cast<int>((cos_val + 1) * (width / 2));

        // if the degree += value is greater you might not see the X
        if(std::abs(pos_1 - pos_2) <= 1)
        {
            std::cout << std::string(pos_1, ' ') << "🟢" << '\n';
        }
        else if(pos_1 < pos_2)
        {
            std::cout << std::string(pos_1, ' ') 
                      << "🟣" << std::string(pos_2 - pos_1 - 1, ' ') 
                      << "🟡" << '\n';
        }
        else
        {
            std::cout << std::string(pos_2, ' ') 
                      << "🟣" << std::string(pos_1 - pos_2 - 1, ' ') 
                      << "🟡" << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // reverse curve
    for(double degrees = 360; degrees >= 0; degrees -= interval)
    {
        double radians = degrees * (PI / 180.0);

        double sine_val = std::sin(radians);
        double cos_val = std::cos(radians);

        int pos_1 = static_cast<int>((sine_val + 1) * (width / 2));
        int pos_2 = static_cast<int>((cos_val + 1) * (width / 2));

        // if the degree -= value is greater you might not see the X
        if(std::abs(pos_1 - pos_2) <= 1)
        {
            std::cout << std::string(pos_1, ' ') << "🟢" << '\n';
        }
        else if(pos_1 < pos_2)
        {
            std::cout << std::string(pos_1, ' ') 
                      << "🟣" << std::string(pos_2 - pos_1 - 1, ' ') 
                      << "🟡" << '\n';
        }
        else
        {
            std::cout << std::string(pos_2, ' ') 
                      << "🟣" << std::string(pos_1 - pos_2 - 1, ' ') 
                      << "🟡" << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void breathing_bar()
{
    const int width = 50;

    for(double i = 0; ; i += 0.05)
    {
        double sine_val = std::sin(i);

        int bar_length = static_cast<int>((sine_val + 1.0) * (width / 4));

        // move cursor to start and clear the line
        std::cout << "\r\033[2K";

        std::string bar(bar_length, '@');
        std::cout << "\033[38;2;122;162;247m" << bar << "\033[0m" << std::flush;
        //std::cout << " (val: " << sine_val << ')' << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

int main()
{
    sin_cos_helix();
    //breathing_bar();
    return 0;
}
