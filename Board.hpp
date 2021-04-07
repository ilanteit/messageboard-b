#include <string>
#include <map>
#include "Direction.hpp"
/*
    Board.hpp.
    Author: Tal Schreiber.
*/
using namespace std;

struct deafult
{
    char v = '_'; // filling the "empty" spaces of the board with '_'
};

namespace ariel

{
    
    class Board
    {
        map<unsigned int, map<unsigned int, deafult>> board;
        bool firstTime;
        unsigned int left_col;
        unsigned int right_col;
        unsigned int low_row;
        unsigned int high_row;

    public:
        Board()
        {
            firstTime = true;
            left_col = 0;
            right_col = 0;
            low_row = 0;
            high_row = 0;
        }
        ~Board(){}; // class's destructor
        void post(unsigned int row, unsigned int col, Direction direction, std::string message);
        std::string read(unsigned int row, unsigned int col, Direction direction, unsigned int length);
        void show();
    };

}