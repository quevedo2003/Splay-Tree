#include <iostream> 

bool is_prime(int n, int counter){
   

   if(counter == n/2){
    //  std::cout << "false beacuse n = " << n << " or counter  = " << counter << std::endl;
     return true;
   }
   else if(n % counter == 0 || n == 1 || n == 2){
        // std::cout << "true because counter = " << counter << " n = " << n << std::endl;
        return false;
   }
   else{

        counter++;
        // std::cout << "else counter++ = " << counter << std::endl;
        return is_prime(n,counter);
   } 


}

//6 is not prime
int main(int argc, char*argv[]){

    int num;
    
    num = std::stoi(argv[1]);

    std::cout << is_prime(num,2) << std::endl;

}

