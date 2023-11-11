#include "maze.h"
#include<iostream>

//implementation of all methods defined in maze.h

bool bounds_check(int row_size, int col_size, int current_col_index,  int current_row_index){

    bool inbound = true;

    if(current_row_index < 0 || current_col_index < 0 || current_row_index > row_size || current_col_index > col_size){
        inbound = false;
    }

    return inbound;

}

bool upper_bound(int row_size, int current_row_index){
    if(current_row_index < 0 || current_row_index > row_size){
        return false;
    }
    else return true;
}

bool side_bound(int col_size, int current_col_index){
    if(current_col_index < 0 || current_col_index > col_size){
        return false;
    }
    else return true;
}


//Constructor
maze::maze(int num_seed, int num_row, int num_col){
    this->seed = num_seed;
    this->col = num_col;
    this->row = num_row;
    
    make_maze(seed,row,col);
    
    maze_generation();
    
}

//Making the grid 
void maze::make_maze(int num_seed, int num_row, int num_col){
   
    // int x;
    // x = num_row;
    // num_row = num_col;
    // num_col = x;

    std::srand(num_seed);
    //  std::vector<std::vector<int>> a;
   
    // debug
    // std::cout << "-- Init grids" << std::endl;

    std::vector<std::vector<int>> initialized_grid;
    std::vector<std::vector<bool>> visited_grid;

    //Initializing my vector grid
    for(int i = 0; i < num_row; i++){      
          
        std::vector<int> temp;
        std::vector<bool> temp_bool;
       
        for(int j = 0; j < num_col; j++){
           
            temp.push_back(15);
            temp_bool.push_back(false);
        }
        initialized_grid.push_back(temp);
        visited_grid.push_back(temp_bool);
    }
    
    

    if(num_row == 1 && num_col == 1){
        initialized_grid[0][0] = 3;
    }
    else{
        
    initialized_grid[0][0] = 7; //setting my first cell to have north wall removed
    initialized_grid[num_row - 1][num_col - 1] = 11; //setting my last cell in grid to have south wall removed
    
    }
    // mark cell [0,0] as visited
    visited_grid[0][0] = true;

    

   this->grid = initialized_grid;
   this->visited = visited_grid;
}

//Checking if cell is visited
bool maze::Is_Visited(int x, int y){
    
   
    if(this->visited[x][y]){
        return true;
    }
    else{
       
        return false;    
    }

}



void maze::maze_generation(){
    // std::cout << "Checkpoint 1" << std::endl;
    // create empty dynamic array `A`
    std::vector<std::pair<int,int>> dynamic_array;   

    // insert cell [0,0] at the end of `A`
    dynamic_array.push_back({0,0});
    
    
  // while `A` is not empty
    while(dynamic_array.size() != 0){
       std::pair<int, int> current; 
       std::vector<std::pair<int,int>> neighbor;

        //`current` <- remove last element from `A`
        current = dynamic_array[dynamic_array.size() - 1];
        dynamic_array.pop_back();

        // debug
        // std::cout << "Checkpoint 2" << std::endl;

        //`neighbors` <- `current`'s neighbors not visited yet
        //Checking if all four neighbors are visited, then adding it empty into the neighbor array
         
        //   Above 
        
        if(current.first - 1 >= 0){  
          
           if( !Is_Visited(current.first - 1, current.second) /*bounds_check(this->col, this->row, current.first - 1, current.second)*/ ){
                neighbor.push_back( {current.first - 1, current.second} );
           }            
        } 
        //Below
        if( current.first + 1 < row){
            
              if(!Is_Visited(current.first + 1, current.second)  /*bounds_check(this->col, this->row, current.first + 1, current.second)*/ ){
            
            neighbor.push_back( {current.first + 1, current.second} );
            }
        }     
        //Right
        if (current.second + 1 < col){ 
           
            if(!Is_Visited(current.first, current.second + 1) /*bounds_check(this->col, this->row, current.first, current.second + 1)*/ ){
            
            neighbor.push_back( {current.first, current.second + 1} );
            }
        }
        //Left
        if(current.second - 1 >= 0){  
            
            if(!Is_Visited(current.first, current.second - 1) /*bounds_check(this->col, this->row, current.first, current.second - 1) */){
            
            neighbor.push_back( {current.first, current.second - 1} );
            }
        }
        
        // debug
        // std::cout << "Checkpoint 3" << std::endl;

    //if `neighbors` is not empty
        if(neighbor.size() != 0){
           
           //insert `current` at the end of `A`
            dynamic_array.push_back(current);

            std::pair<int, int> neigh;

           //`neigh` <- pick a random neighbor from `neighbors`
            // neigh = neighbor[std::rand() % neighbor.size()];
            neigh = neighbor[std::rand() / ( (RAND_MAX + 1u)/neighbor.size() )];

            // debug
            // std::cout << "Checkpoint 4" << std::endl;
            
            // debug
            // std::cout << "Printing maze from rand neighbor loop 1" << std::endl;

            // for(int i = 0; i < row; i++){
            //     for(int j = 0; j < col; j++){
            //         std::cout<<this->grid[i][j]<<" ";
            //     }
            //     std::cout<<std::endl;
            // }

            // debug
            // std::cout << "Printing maze from rand neighbor loop 2" << std::endl;

            // for(int i = 0; i < neighbor.size(); i++){
            //     std::cout<<neighbor[i].first<<" "<<neighbor[i].second<<std::endl;
            // }

            // debug
            // std::cout << "Checkpoint 5" << std::endl;

            // debug
            // std::cout << "Printing maze from rand neighbor loop 3" << std::endl;

            // std::cout<<"Random Neighbor Selected --> "<<neigh.first<< " "<<neigh.second<<std::endl;

            // this->grid[current.first][current.second];
        
            //remove the wall between `current` and `neigh`
            if(current.first - 1 == neigh.first){
                //Upper neighbor || North
                
                //Upper wall = 8
                //Lower wall = 4

                grid[current.first][current.second] -= 8;
                grid[neigh.first][neigh.second] -= 4;

            }
            if(current.first + 1 == neigh.first){
                //Lower neighbor || South
                
                //Upper wall = 8
                //Lower wall = 4
                
                grid[current.first][current.second] -= 4;
                grid[neigh.first][neigh.second] -= 8;
           }
           if (current.second + 1 == neigh.second){
                //Right neighbor || East

                //Right wall = 1
                //Left wall = 2

                grid[current.first][current.second] -= 2;
                grid[neigh.first][neigh.second] -= 1;
           }
           if(current.second - 1 == neigh.second){
                //Left neighbor || West

                //Right wall = 1
                //Left wall = 2

                grid[current.first][current.second] -= 1;
                grid[neigh.first][neigh.second] -= 2;

            }

            // debug
            // std::cout << "Checkpoint 6" << std::endl;

            //mark `neigh` as visited 
            visited[neigh.first][neigh.second] = true;
            
            //insert `neigh` at the end of `A`
            dynamic_array.push_back(neigh);

            // debug
            // std::cout << "Checkpoint 7" << std::endl;

            //endif
        }
        
        // neighbor.clear();
        
        //endwhile
    }

}



void maze::print_maze(){

    for(int i = 0; i < row; i++){
        
        for(int j = 0; j < col; j++){
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