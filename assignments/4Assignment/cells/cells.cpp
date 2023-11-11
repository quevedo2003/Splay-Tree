#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>


class Cell{

    private:

    int row;
    int col;
    int connection;
    int selected_row;
    int selected_col;
    std::vector<std::vector<int>> grid;


    public:

    Cell(std::string fname);
    int countCells(int row, int col, int selected_row,int selected_col, int connection);
    int counter(int connection ,int selected_row, int selected_col, int row, int col);
    bool bound_checker(int row, int col, int num_row, int num_col);
    // ~Cell();
    

    void print( int row, int col);


};


//Reading a given cell
Cell::Cell(std::string fname){
    // std::cout << "test in Cell" << std::endl;
    std::ifstream file(fname);
    std::string line;
    std::vector<int> value_matrix;
    std::vector<std::vector<int>> matrix;
    int value;

   while(std::getline(file,line)){
    std::stringstream ss(line);
    int value;
    std::vector<int> row_vector;

    while(ss >> value){
        row_vector.push_back(value);
    }
    matrix.push_back(row_vector);

   }
    
   grid = matrix;

    //print(10, 10);

}


bool Cell::bound_checker(int row, int col, int num_row, int num_col){
//    std::cout << "bound_checker" << std::endl; 
	if(row > 0 && col > 0 && row <= num_row && col <= num_col){
        return true;
    }
    else{
        return false;
    }

}

int Cell::counter(int connection ,int selected_row, int selected_col, int row, int col){
    // std::cout << "Test counter" << std::endl;
    
     // Check if we are out of bounds
    if(!bound_checker(selected_row, selected_col, row, col) || grid[selected_row - 1][selected_col - 1] == 0){
        return 0;
    }

    int currentValue = grid[selected_row - 1][selected_col - 1];

    // Mark the cell as visited
    grid[selected_row - 1][selected_col - 1] = 0;

    // Calculate the count recursively
    int count = 1;

    //We will just assume the connection is type 4
    count += counter(connection, selected_row - 1, selected_col, row, col); // Up
    count += counter(connection, selected_row + 1, selected_col, row, col); // Down
    count += counter(connection, selected_row, selected_col - 1, row, col); // Left
    count += counter(connection, selected_row, selected_col + 1, row, col); // Right

    if(connection == 8){
        count += counter(connection, selected_row - 1, selected_col - 1, row, col); // Top-left
        count += counter(connection, selected_row - 1, selected_col + 1, row, col); // Top-right
        count += counter(connection, selected_row + 1, selected_col - 1, row, col); // Bottom-left
        count += counter(connection, selected_row + 1, selected_col + 1, row, col); // Bottom-right
    }

    return count;
}



int Cell::countCells(int row, int col, int selected_row,int selected_col, int connection){
    int sum = 0;
    
    sum = counter(connection ,selected_row, selected_col, row, col);

    return sum;
    
}


void Cell::print( int row, int col){
    // std::cout << "Test in Print" << std::endl;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col; j++){
            std::cout<<grid[i][j];
        }
        std::cout<<std::endl;
    }
}



int main(int argc, char * argv[]){
    int row,col,connection,selected_row,selected_col;

    Cell test(argv[1]);
  

    row = atoi(argv[2]);
    col = atoi(argv[3]);
    selected_row = atoi(argv[4]);
    selected_col = atoi(argv[5]);
    connection = atoi(argv[6]);

    
    // std::cout << "test in main" << std::endl;
    // test.countCells(row,col,selected_row,selected_col,connection);

  std::cout << test.countCells(row,col,selected_row,selected_col,connection) << std::endl;

}
