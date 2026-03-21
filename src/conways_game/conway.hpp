#include <vector>

class Conway
{
    public:
        int rows;
        int cols;
        std::vector<std::vector<int>> curr_grid; // vector grid
        std::vector<std::vector<int>> next_grid; // vector grid

        // constructor
        Conway(int rows, int cols);
};
