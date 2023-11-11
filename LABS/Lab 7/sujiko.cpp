#include "sujiko.h"

//Since row and col will be a 3x3 regardless, I can declare 
// it beyond the scope of any function.
const unsigned int row = 3;
const unsigned int col = row;



Sujiko::Sujiko() {

}

Sujiko::Sujiko(std::string fname) {
    // Read 4 sum values from file
    //I will place them into sum_value
    
    std::ifstream file(fname);
    std::string line;
    int value;
    std::vector<unsigned int> sum_value;

    if(std::getline(file,line)){
        std::stringstream ss(line);

        while(ss >> value){
            sum_value.push_back(value);
        }

    //   nums[0][0] = sum_value[0];
    //   nums[0][1] = sum_value[1];
    //   nums[1][0] = sum_value[2];
    //   nums[1][1] = sum_value[3];

    }


    //*Debugging*
    // for(int i = 0; i < 4; i++){ std::cout<< sum_value[i] << " ";}
    // std::cout<<std::endl;
   
    //sum_value holds the four digit input

    std::vector<std::vector<unsigned int>> grid;

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::vector<unsigned int > input_matrix;
        int input_value;
       
        while(ss >> input_value){
          input_matrix.push_back(input_value);
        }
        grid.push_back(input_matrix);
    }

    this->sum_value = sum_value;
    board = grid;
    // this->sum_value = sum_value;
}

Sujiko::~Sujiko() {
//Small enough program to not need a destructer
}



bool Sujiko::sum(std::vector<std::vector<unsigned int>>& board){
    int circle_1 = board[0][0]+board[0][1]+board[1][0]+board[1][1];
    int circle_2 = board[0][1]+board[0][2]+board[1][1]+board[1][2];
    int circle_3 = board[1][0]+board[1][1]+board[2][0]+board[2][1];
    int circle_4 = board[1][1]+board[1][2]+board[2][1]+board[2][2];

        
    if(circle_1 == this->sum_value[0] && circle_2 == this->sum_value[1] && circle_3 == this->sum_value[2] && circle_4 == this->sum_value[3]){
        return true;
    }
    else{
    return false;
    }
}

void row_or_col_picker(unsigned int cell, unsigned int& num_row, unsigned int& num_col){
    
    num_row = cell / 3; // Integer division to get the row
    num_col = cell % 3;
 
}

std::vector<unsigned int> present_numbers(std::vector<std::vector<unsigned int>>& board){
    std::vector<unsigned int> present_number;

    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] != 0){
                present_number.push_back(board[i][j]);
            }
        }
    }

    return present_number;
}

std::vector<unsigned int> is_found(std::vector<unsigned int> present_number){
     std::vector<unsigned int> indeces;
     for(int i = 1; i < 10; i++){
        bool found = false;
       
        for(int j = 0; j < present_number.size(); j++){
            if(present_number[j] == i){
                found = true;
                break;
            }
        }
        
        if(!found){
            indeces.push_back(i);
        }
    }
    return indeces;
}


bool Sujiko::solve(unsigned int cell){
    // If we placed a number succesfully on every cell, we did it!
    unsigned int num_row,num_col;
   if(cell == 9){
        if(sum(board)){
            return true;
        }
        else{
            return false;
        }

    }


    row_or_col_picker(cell,num_row,num_col);

  

    if(board[num_row][num_col] != 0){
        return solve(cell + 1);
    }


    std::vector<unsigned int> present_number;
    present_number =  present_numbers(board);
    

    std::vector<unsigned int> indeces;
    indeces = is_found(present_number);
    
     
   
    if (board[num_row][num_col] == 0) {
        // Try each index from indeces
        for (unsigned int i : indeces) {
            board[num_row][num_col] = i;
            if (solve(cell + 1)) {
                return true;
            }
            // If the current placement doesn't lead to a solution, reset the cell to 0
            board[num_row][num_col] = 0;
        }
    }

    return false;
}

void Sujiko::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << this->board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    Sujiko s(argv[1]);

    s.solve(0);

    s.display_board();

    return 0;
}
