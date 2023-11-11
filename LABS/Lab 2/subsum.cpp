#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdint>
#include <iomanip>
#include <vector>
#include <fstream>


int MaxSubSum1(std::vector<int> a) {
	int maxSum = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 1; j < a.size(); ++j) {
			int thisSum = 0;

			for (int k = i; k <= j; ++k) {
				thisSum += a[k];
			}

			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int MaxSubSum2(std::vector<int> a) {
	int maxSum = 0;

	for (int i = 0; i < a.size(); ++i) {
		int thisSum = 0;

		for (int j = i; j < a.size(); ++j) {
			thisSum += a[j];

			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}


int MaxSubSum3(std::vector<int> a){
    int sum = 0;
    int max_sum = 0;
    int min_sum = 0;
    int min_index = 0;
    int max_start = 0;
    int max_end = 0;
    
    for(unsigned int i = 0; i < a.size(); i++){
        sum += a[i];
        
        if(sum < min_sum){
            min_sum = sum;
            min_index = i;
        }
        
        if(sum - min_sum > max_sum){
            max_sum = sum - min_sum;
            max_start = min_index + 1;
            max_end = i + 1;
        }
    }
    return max_sum;
}

int MaxSubSum4(std::vector<int> a) {
	int max_so_far = 0;
	int max_ending_here = 0;

	for (unsigned int i = 0; i < a.size(); i++) {
		max_ending_here += a[i];

		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
		}

		if (max_ending_here < 0) {
			max_ending_here = 0;
		}
	}
	return max_so_far;
}





int main(){


}