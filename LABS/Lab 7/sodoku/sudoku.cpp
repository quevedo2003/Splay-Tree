#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>



//Default constructor sets everything to 0.
Sudoku::Sudoku() {

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            board[i][j] = 0;
        }
    }
}

Sudoku::~Sudoku() {
//Destructor
}

//One argument constructor that reads text file of board
Sudoku::Sudoku(std::string f_name) {
  // Generate a board from the give file
    std::ifstream file(f_name);
    std::string line;
    std::vector<std::vector<unsigned int>> grid;

   
    for(int i = 0; i < 9; i++){
        grid.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0});
    }

    int row = 0;

    while (std::getline(file, line) && row < 9){
        std::vector<unsigned int>& currentRow = grid[row];
        std::stringstream ss(line);
        unsigned int value;
        int col = 0;

        while (ss >> value && col < 9) {
            currentRow[col] = value;
            col++;
        }

        row++;
    }

    board = grid;

    // for(int i = 0; i < 9; i++){
    //     for(int j = 0; j < 9; j++){
    //         std::cout << grid[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << std::endl;

}


bool Sudoku::find_empty_cell(unsigned int& row, unsigned int& col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(board[row][col] == 0){
                return true; // Found an empty cell
            }
        }
    }
    return false; // All cells are filled
}

bool Sudoku::is_empty( std::vector<std::vector<unsigned int>>& board){
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                return true;
            }
        }
    }

    return false;

}

bool Sudoku::solve() {
   
  for (unsigned int row = 0; row < BOARD_SIZE; row++) {
        for (unsigned int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(row, col, num)) {
                        board[row][col] = num;
                        if (solve()) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return !check_row(row, num) && !check_col(col, num) && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){
     for (unsigned int col = 0; col < BOARD_SIZE; col++) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
   
}

bool Sudoku::check_col(unsigned int col, unsigned int num){
  for(unsigned int row = 0; row < BOARD_SIZE; row++){
        if(board[row][col] == num){
            return true;
        }
    }
    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){
  for(unsigned int row = 0; row < 3; row++){
        for(unsigned int col = 0; col < 3; col++){
            if(board[row + boxStartRow][col + boxStartCol] == num){
                return true;
            }
        }
    }
    return false;	
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}
