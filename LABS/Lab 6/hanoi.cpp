#include <iostream>

void hanoi(int num_disks, int source_rod, int destination_rod, int new_rod){

    //Base case means you only have one disk left to move, that being the smallest
    if(num_disks == 1){
        std::cout<< "Move disk " << num_disks << " from tower " << source_rod << " to tower " << destination_rod << std::endl;
    }
    else{
//Moves whatever disk on top from the source rod into the new rod
        hanoi(num_disks - 1, source_rod, new_rod, destination_rod);
//Move the largest disk from the source rod into the destination rod 
        std::cout<< "Move disk " << num_disks << " from tower " << source_rod << " to tower " << destination_rod << std::endl;
//Move the didks from the new rod into the destination rod
        hanoi(num_disks - 1, new_rod, destination_rod, source_rod);
    }

}

int main(int argc, char*argv[]){
    int num_disks, source_rod, destination_rod, new_rod;

    //Number of total disks
    num_disks = std::stoi(argv[1]);
    //Where the rods start
    source_rod = std::stoi(argv[2]);
    //End goal destination of where the rods need to be placed
    destination_rod = std::stoi(argv[3]);

    //new rod based on the sum of all rods ( 1 + 2 + 3  = 6) to move the disks to get to solution
    new_rod = 6 - source_rod - destination_rod;

    hanoi(num_disks, source_rod, destination_rod, new_rod);


}