#include <iostream>

int main(){
        int multiple(float a, float b){
        int lcm = 1;
     if (a == b){
            return a;
     else if (b % 2 != 0){
         return b*a;
     }
    else{
        return (multiple(a,b-1)+a)/2;
        }
     
     }


    
}