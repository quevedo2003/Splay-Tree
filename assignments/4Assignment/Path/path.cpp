#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void find_smallest(std::vector<std::vector<int>> matrix, std::pair<int, int>& smallest){
    
    for(int i = 0; )



}


std::vector<std::vector<int>> read_from_file(std::string& input){
   
    std::ifstream file(input);
    std::vector<std::vector<int>> matrix;
    std::string line;

    while(std::getline(file,line)){
        std::vector<int> row;
        std::istringstream  ss(line);
        int value;

        while(ss >> value){
            row.push_back(value);
        }

        matrix.push_back(row);


    }

    file.close();

    return matrix;

}

int main(int argc, char * argv[]){
    
    std::string input_matrix = argv[1];
    std::vector<std::vector<int>> grid = read_from_file(input_matrix);
    
    int row = argv[2];
    int col = argv[3];

    bool possible = possible_path(grid);

    std::pair<int, int> small = {0,0};
    find_smallest(grid, small);
    
    std::pair<int, int> largest = {0,0}; 
    find_largest(grid, largest);

     
}