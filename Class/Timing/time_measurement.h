// time_measurement.h


//Since this is a small enough class, I have decided to define everything here which will mean less files to compile

#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H

#include "splay_tree.h"
#include <chrono> 
#include <iostream> 

class Time {
public:
    template <typename Func, typename... Args>
    
    //This function essentially acts as a clock to take and takes the difference between the end and start
    //Template function that takes a callable object and a variable number of arguments
    static double measure(Func&& func, Args&&... args){
        //Using the chrono library to obtain the current time and place it into start
        auto start = std::chrono::high_resolution_clock::now();
        //Uses forward to forward both the callable object and its arguments to preserve their value categories
        std::forward<Func>(func)(std::forward<Args>(args)...);
        //Captures the current time after the execution of the callable object and its arguments
        auto end = std::chrono::high_resolution_clock::now();

        //Records the duration by taking the difference from end and start time
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    static void printTime(double seconds){  
        if(seconds >= 1){
            std::cout << "Time: " << seconds << " seconds" << std::endl;
        }
        else{
            //Else we will represent the time in miliseconds
            std::cout << "Time: " << seconds * 1000.0 << " milliseconds" << std::endl;
        }
    }
};

#endif
