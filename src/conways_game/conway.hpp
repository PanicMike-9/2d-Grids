#pragma once

#include <vector>

class Conway
{
    public:
        // constructor
        Conway(int rows, int cols);

        void generate_random();
        void update();
        void display() const;

    private:
        int rows;
        int cols;
        int generation;
        // vector grid
        std::vector<std::vector<int>> curr_grid; 
        std::vector<std::vector<int>> next_grid; 

        int count_neighbors(int r, int c) const;
};

