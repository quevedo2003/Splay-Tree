// #include <iostream>
// #include <cstdlib>
// #include <ctime>
#include "maze.h"

// Driver program that takes CLAs and uses the class Maze to generate output
// Assignment 2 Maze

//calling my functions defined and declared in my other two files

//All test cases that I need to check for
//5x5           1x15
// 150x150      24x7
//500x500       2x2
// 1x1

//All inputs go here

int main(int argc, char *argv[]){
    
    int seed, col_input, row_input;

    //first argumenr is seed, second is rows, third is coloumns, fourth is filename
           
            //string to integer
    seed = std::stoi(argv[1]);
    row_input = std::stoi(argv[2]);
    col_input = std::stoi(argv[3]);

    // std::srand(seed);
        

    
    maze new_maze(seed, row_input, col_input);

    // new_maze.make_maze(seed, row_input, col_input);

    new_maze.maze_generation();

    std::ofstream outputFile("output-stu.txt");

    

    new_maze.print_maze();

    for(int i = 0; i < row_input; i++){
        for(int j = 0; j < col_input; j++){
            outputFile << new_maze.grid[i][j] << " ";
        }
        outputFile << std::endl;
    }
    

    outputFile.close();

    // <seed>  the seed value for the random number generator
    // <N>     number of rows in the grid N > 0
    // <M>     number of cols in the grid M > 0
    // <fname> file name for the output



}



// bool bounds_check(int num_col,  int num_row,  int current_col_index,  int current_row_index){

//     bool inbound = true;

//     if(current_row_index < 0 || current_col_index < 0 || current_row_index >= num_row || current_col_index >= num_col ){
//         inbound = false;
//     }

//     return inbound;

// }