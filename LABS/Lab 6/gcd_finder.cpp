#include <iostream>

int gcd(int a, int b) {
    
    if(b == 0){
        return a;
    } 
    else{
        return gcd(b, a % b);
    }

}
// 10 45 5 
int main(int argc, char*argv[]){

    int num_one,num_two;

    num_one = std::stoi(argv[1]);
    num_two = std::stoi(argv[2]);

    std::cout << gcd(num_one,num_two) << std::endl;

}