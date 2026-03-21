#include <vector>

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
        std::vector<std::vector<int>> curr_grid; // vector grid
        std::vector<std::vector<int>> next_grid; // vector grid
};
