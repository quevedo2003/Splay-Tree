#include <iostream>
#include <vector>
#include <algorithm>


void permutation(std::vector<int>& vect, int index) {
    
   do{
        for (int i = 0; i < vect.size(); i++) {
            std::cout << vect[i] << " ";
        }
        std::cout << std::endl;
    } 
    while( std::next_permutation(vect.begin(), vect.end()) );
}


//2
// 1 2
// 2 1
int main(int argc, char*argv[]){
    
    int num;
    num = std::stoi(argv[1]);
    std::vector<int> vect;

    for(int i = 1; i <= num; i++){
       
        vect.push_back(i);
    }
    
    permutation(vect,0);

}