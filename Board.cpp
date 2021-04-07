#include "Board.hpp"
#include <iostream>
using namespace std;

namespace ariel
{

    void Board::post(unsigned int row, unsigned int colum, Direction direct, std::string message)
    {
        // start();
        if (this->firstTime)
        {
            this->firstTime = false;
            this->left_col = colum;
            this->low_row = row;
        }
        unsigned int length = message.size();
        if (direct == Direction::Horizontal)
        {

            for (unsigned long j = 0; j < length; j++)
            {
                unsigned long i = row;
                this->board[i][colum + j].v = message[j];
                this->high_row = max(this->high_row, row);
                this->right_col = max(this->right_col, colum + length);
            }
        }
        if (direct == Direction::Vertical)
        {
            for (unsigned long i = 0; i < length; i++)
            {
                unsigned long j = colum;
                this->board[i + row][j].v = message[i];
                this->high_row = max(this->high_row, row + length);
                this->right_col = max(this->right_col, colum);
            }
        }
        this->low_row = min(this->low_row, row);
        this->left_col = min(this->left_col, colum);
    }

    string Board::read(unsigned int row, unsigned int colum, Direction direct, unsigned int length)
    {
        string newMessage;

        if (direct == Direction::Horizontal)
        {

            for (unsigned long j = 0; j < length; j++)
            {

                unsigned long i = row;
                newMessage += this->board[i][colum + j].v;
            }
        }
        if (direct == Direction::Vertical)
        {
            for (unsigned long i = 0; i < length; i++)
            {
                unsigned long j = colum;
                newMessage += this->board[i + row][j].v;
            }
        }
        return newMessage;
    }

    void Board::show() {
        for (uint i = this->low_row; i < this->high_row; i++) {
            cout << i<< ": ";
            for (uint j = this->left_col; j < this->right_col; j++) {
                cout << this->board[i][j].v ;
            }
            cout << "\n";
        }
    }
}