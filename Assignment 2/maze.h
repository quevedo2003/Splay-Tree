#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <string>
#include <fstream>


//class declaration


class maze{
    private:
    
    int col;
    int row;
    int seed;
    std::vector<std::vector<bool>> visited;
   
    //All other grid related vectors would go here
    // bool Is_Visited(int x, int y); 
    

    public:
    //all methods that relate to checking the grrid, neighbors, and wall breaking go here      
    bool Is_Visited(int x, int y); 
    std::vector<std::vector<int>> grid;
    // std::vector<std::vector<int>> grid;

    maze(int seed, int num_row,int num_col);

    void make_maze(int num_seed, int num_row, int num_col);
    void  maze_generation();

    void print_maze();
};

#endif