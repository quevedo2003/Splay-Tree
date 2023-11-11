#include <iostream>


void row_or_col_picker(unsigned int cell, unsigned int& num_row, unsigned int& num_col){
    
    num_row = 3;
    num_col = 3;
 
}


bool solve(unsigned int cell){
  
   unsigned int num_row,num_col;
    std::cin >> num_row, num_col;
    std::cout << " before function row = " << num_row << " and col = " << num_col << std::endl;

    row_or_col_picker(cell,num_row,num_col);

    std::cout << " after function row = " << num_row << " and col = " << num_col << std::endl;
    return true;
    

}

int main(){
    solve(0);
    
}