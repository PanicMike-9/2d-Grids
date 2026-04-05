#include "conway.hpp"

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

void Conway::update()
{
    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < cols; ++c)
        {
            int alive_neighbors = count_neighbors(r, c);

            if(curr_grid[r][c] == 1)
            {
                if(alive_neighbors < 2 || alive_neighbors > 3)
                    next_grid[r][c] = 0;

                else
                    next_grid[r][c] = 1;
            }
            else
            {
                if(alive_neighbors == 3)
                    next_grid[r][c] = 1;

                else
                    next_grid[r][c] = 0;
            }
        }
    }

    curr_grid = next_grid;
}

void Conway::display() const
{
}
