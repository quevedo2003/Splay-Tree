//time_test.cpp

#include "splay_tree.h"
#include "time_measurement.h"
#include <fstream>

int main(){
    STree history;

    history.insert("test");
    history.insert("hello");
    history.insert("check");
    history.insert("new");

    std::cout << "Tree before splay search" << std::endl;
    history.preOrder();

    //Lambda function 
    double executionTime = Time::measure([&history]() { history.splaySearch("hello"); });

    std::cout << "Tree after splay search" << std::endl;
    history.preOrder();

    Time::printTime(executionTime);

    history.dot_gen("test.dot");

    return 0;
}
