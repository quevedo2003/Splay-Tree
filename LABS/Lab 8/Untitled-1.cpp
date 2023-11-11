#include <iostream>
#include <string>


int big(int a,int b){
    if(a > b){
        return a;
    }
    else if(a < b){
        return b;
    }
}

int main(){


    int a, b;
    std::cin >> a;
    std::cin >> b;

    int x = big(a,b);
    std::cout << x << std::endl;

}

