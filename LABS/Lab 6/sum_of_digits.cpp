#include <iostream>
#include <fstream> 


int sum(int n);

int main(int argc, char*argv[]){
    int num;
    
    num = std::stoi(argv[1]);
   
    //Input will be CLA 1     
    std::ifstream file(argv[1]);

   

    std::cout << sum(num) << std::endl;

    
   
}

//12345 = 1 + 2 + 3 + 4 + 5  = 15
int sum(int n){
    int holder = n;
    int temp = n;
    if(holder != 0){

        temp = holder % 10;
        holder /= 10;
        return sum(holder) + temp;
    }
    else{
        return 0;
    }


}

