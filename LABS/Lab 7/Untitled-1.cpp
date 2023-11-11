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
    std::vector<int> sum_value;

    if(std::getline(file,line)){
        std::stringstream ss(line);

        while(ss >> value){
            sum_value.push_back(value);
        }

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


   
     // Display the grid (*Debugging*)
                //   for(int i = 0; i < 3; i++){
                //     for(int j = 0; j < 3; j++){
                //         std::cout << grid[i][j] << " ";
                //     }
                //   }

    // Read file & create board
    board = grid;
}

Sujiko::~Sujiko() {
//Small enough program to not need a destructer
}

//Checks if there is a number in every cell
bool board_check(std::vector<std::vector<unsigned int> > board){
    // const int row = 3;
    // const int col = row;
    bool checker = true;

  
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col;j++){
            if(board[i][j] == 0){
                checker = false;
            }
        }
    }

    return checker;
}

//Record the indeces in which board = 0
void indeces( std::vector<std::vector<unsigned int> >& board, std::vector<std::vector<unsigned int> >& index){
    
    for(unsigned int i = 0; i < row; i++){
        for(unsigned int j = 0; j < col; j++){
            if(board[i][j] == 0){
               index.push_back({i, j});
            }
        }
    }



    //   for(int i = 0; i < index.size() ; i++){
    //         std::cout << index[i][0] << " " <<  index[i][1] << std::endl;
    // }

}

bool not_used(std::vector<std::vector<unsigned int>>& board, unsigned int rowIndex, unsigned int colIndex, unsigned int num) {
    


    for (unsigned int i = 0; i < 9; i++) {
        if (board[rowIndex][i] == num || board[i][colIndex] == num || board[3 * (rowIndex / 3) + i / 3][3 * (colIndex / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}


void replacer(std::vector<std::vector<unsigned int> >& board){
     
     //index holds the indeces in which board is equal to 0.
    std::vector<std::vector<unsigned int> > index;
    indeces(board,index);
    std::cout << "CHECKPOINT 1" << std::endl;
    if(index.size() == 0){
        return;
    }
    std::cout << "CHECKPOINT 2" << std::endl;
    for(int number_cell = 1; number_cell <= 9; number_cell++){
        std::cout << "CHECKPOINT 3" << std::endl;
        for(unsigned int i = 0; i < index.size();i++){
            unsigned int num_row = index[i][0];
            unsigned int num_col = index[i][1];
            std::cout << "CHECKPOINT 5" << std::endl;
            if(not_used(board,num_row,num_col, number_cell) ){
               std::cout << "CHECKPOINT 6" << std::endl;
                board[num_row][num_col] = number_cell;
                


                if(board_check(board)){
                    return;
                }

            }
            
            board[num_row][num_col] = 0;
        }
    }
   
    // std::cout << std::endl;
    
    index.clear();
}

bool Sujiko::solve(unsigned int cell){
    // If we placed a number succesfully on every cell, we did it!
    if(board_check(board) == true){
        std::cout << "You win!" << std::endl;
        return true;
    }
    else{
        replacer(board);
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
