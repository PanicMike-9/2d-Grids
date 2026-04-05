#include <vector>

#ifndef CONWAY_HPP
#define CONWAY_HPP

class Conway
{
    public:
        // constructor
        Conway(int rows, int cols);

        void update();

        void display() const;

    private:
        int rows;
        int cols;
        // vector grid
        std::vector<std::vector<int>> curr_grid; 
        std::vector<std::vector<int>> next_grid; 

        int count_neighbors(int r, int c) const;
};

#endif
