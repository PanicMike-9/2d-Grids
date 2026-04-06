#include "conway.hpp"
#include "ansi.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

Conway::Conway(int rows, int cols) : rows{rows}, cols{cols} 
{
    curr_grid.resize(rows);
    next_grid.resize(rows);

    for(int i = 0; i < rows; ++i)
    {
        curr_grid[i].resize(cols);
        next_grid[i].resize(cols);
    }

}

void Conway::generate_random()
{
    // generate random
    std::srand(std::time(nullptr));

    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < cols; ++c)
        {
            // 20% chance of 1 or 0
            curr_grid[r][c] = (std::rand() % 5 == 0) ? 1 : 0;
        }
    }
}

int Conway::count_neighbors(int r, int c) const
{
    int count = 0;
    int neighbor_r, neighbor_c;

    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            // skip rows
            if(i == 0 && j == 0) continue;

            // calculate neighbor position
            neighbor_r = r + i;
            neighbor_c = c + j;

            // grid check
            if(neighbor_r >= 0 && neighbor_r < rows && neighbor_c >= 0 && neighbor_c < cols)
            {
                if(curr_grid[neighbor_r][neighbor_c] == 1) count++;
            }
        }
    }

    return count;
}

void Conway::update()
{
    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < cols; ++c)
        {
            int alive_neighbors = count_neighbors(r, c);

            // if grid is alive
            if(curr_grid[r][c] == 1)
            {
                if(alive_neighbors < 2 || alive_neighbors > 3) next_grid[r][c] = 0;

                else next_grid[r][c] = 1;
            }

            else
            {
                if(alive_neighbors == 3) next_grid[r][c] = 1;

                else next_grid[r][c] = 0;
            }
        }
    }

    curr_grid = next_grid;
}

void Conway::display() const
{
    std::cout << ansi::move(10, 1);

    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < cols; ++c)
        {
            if(curr_grid[r][c] == 1) std::cout << "🟥";
            else std::cout << "⬜";
        }

        std::cout << '\n';
    }
}
