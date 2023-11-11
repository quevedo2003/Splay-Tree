#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>



class Cell{

    private:

    int row;
    int col;
    std::vector<std::vector<int>> grid;


    public:

    Cell(std::string fname);
    ~Cell();
    

    void print(int row, int col);


};


//Reading a given cell
Cell::Cell(std::string fname){
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

    print(10,10);

}


void Cell::print(int row, int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col; j++){
            std::cout<<grid[i][j];
        }
        std::cout<<std::endl;
    }
}



int main(int argc, char * argv[]){
    Cell test(argv[1]);

}
