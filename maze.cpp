#include "maze.h"

//implementation of all methods defined in maze.h

//Constructor
maze::maze(int num_col, int num_row){
    this->col = num_col;
    this->row = num_row;
}

//Making the grid 
void maze::make_maze(int num_col, int num_row){

    //  std::vector<std::vector<int>> a;
   

    std::vector<std::vector<int>> initialized_grid;
    std::vector<std::vector<bool>> visited_grid;

 
    //Initializing my vector grid
    for(int i = 0; i < num_col; i++){      
        
        std::vector<int> temp;
        std::vector<bool> temp_bool;
       

        for(int j = 0; j < num_row; j++){
           
            temp.push_back(15);
            temp_bool.push_back(false);

        }

        initialized_grid.push_back(temp);
        visited_grid.push_back(temp_bool);
    }



    initialized_grid[0][0] = 7; //setting my first cell to have north wall removed
    initialized_grid[num_col - 1][num_row - 1] = 11; //setting my last cell in grid to have south wall removed
    
    // mark cell [0,0] as visited
    visited_grid[0][0] = true;

    this->grid = initialized_grid;
    this->visited = visited_grid;
}

//Checking if cell is visited
bool maze::Is_Visited(int x, int y){
    
    if(visited[x][y]){
        return true;
    }
    else{
        return false;    
    }

}


void maze::maze_generation(){
    // create empty dynamic array `A`
    std::vector<std::pair<int,int>> dynamic_array;   
    std::pair<int, int> start = {0,0};

    // insert cell [0,0] at the end of `A`
    dynamic_array.push_back(start);
    
    visited[0][0] = true;
    
  // while `A` is not empty
    while(dynamic_array.size() != 0){
       std::pair<int, int> current; 
       std::vector<std::pair<int,int>> neighbor;

        //`current` <- remove last element from `A`
        current = dynamic_array[dynamic_array.size() - 1];
        dynamic_array.pop_back();

    //`neighbors` <- `current`'s neighbors not visited yet
    //Checking if all four neighbors are visited, then adding it empty into the neighbore array
          //Above 
        if(current.first - 1 >= 0 &&  !Is_Visited(current.first - 1, current.second) ){
            
            neighbor.push_back( {current.first - 1, current.second} );

        } //Below
        else if( current.first + 1 < this->col  &&  !Is_Visited(current.first + 1, current.second) ){
            
            neighbor.push_back( {current.first + 1, current.second} );

        } //Left
        else if(current.second - 1 >= 0 &&  !Is_Visited(current.first, current.second - 1) ){
            
            neighbor.push_back( {current.first, current.second - 1} );

        }//Right
        else if (current.second + 1 < this->row &&  !Is_Visited(current.first, current.second + 1) ){
            
            neighbor.push_back( {current.first, current.second + 1} );

        }

    //if `neighbors` is not empty
        if(neighbor.size() != 0){
           
           //insert `current` at the end of `A`
            dynamic_array.push_back(current);

            std::pair<int, int> neigh;

           //`neigh` <- pick a random neighbor from `neighbors`
            neigh = neighbor[std::rand() % neighbor.size()];


            this->grid[current.first][current.second];
        
            //remove the wall between `current` and `neigh`
            if(current.first - 1 == neigh.first){
                //Upper neighbor
                
                //Upper wall = 8
                //Lower wall = 4

                this->grid[current.first][current.second] -= 8;
                this->grid[neigh.first][neigh.second] -= 4;

            }
            else if(current.second - 1 == neigh.second){
                //Left neighbor

                //Right wall = 1
                //Left wall = 2

                this->grid[current.first][current.second] -= 2;
                this->grid[neigh.first][neigh.second] -= 1;

            }
           else if(current.first + 1 == neigh.first){
                //Lower neighbor
                
                //Upper wall = 8
                //Lower wall = 4
                
                this->grid[current.first][current.second] -= 4;
                this->grid[neigh.first][neigh.second] -= 8;
           }
           else if (current.second + 1 == neigh.second){
                //Right neighbor

                //Right wall = 1
                //Left wall = 2

                this->grid[current.first][current.second] -= 1;
                this->grid[neigh.first][neigh.second] -= 2;
           }

            //mark `neigh` as visited 
            this->visited[neigh.first][neigh.second] = true;
            
            //insert `neigh` at the end of `A`
            dynamic_array.push_back(neigh);

            //endif
        }

        //endwhile
    }

}


// std::vector<std::vector<int>> maze::getGrid(){
//     return grid;
// }

void maze::print_maze(){

    for(int i = 0; i < col; i++){
        
        for(int j = 0; j < row; j++){
            std::cout<< grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

}


// create empty dynamic array `A`
// mark cell [0,0] as visited
// insert cell [0,0] at the end of `A`
// while `A` is not empty
//     `current` <- remove last element from `A`
//     `neighbors` <- `current`'s neighbors not visited yet
//     if `neighbors` is not empty
//         insert `current` at the end of `A`
//         `neigh` <- pick a random neighbor from `neighbors`
//         remove the wall between `current` and `neigh`
//         mark `neigh` as visited
//         insert `neigh` at the end of `A`
//     endif
// endwhile

