//Given an integer array nums sorted in non-decreasing order, 
//remove some duplicates in-place such that each unique element appears at most twice. 
//The relative order of the elements should be kept the same.
//Since it is impossible to change the length of the array in some languages, 
//you must instead have the result be placed in the first part of the array nums. 
//More formally, if there are k elements after removing the duplicates, 
//then the first k elements of nums should hold the final result. 
//It does not matter what you leave beyond the first k elements.
//Return k after placing the final result in the first k slots of nums.
//Do not allocate extra space for another array. 
//You must do this by modifying the input array in-place with O(1) extra memory.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void print_vector(vector<int> input) {

    if(input.empty()) {
        cout << "{}";
    }
    else {
        cout << "{\t";
        for(int i = 0; i < input.size(); i++) {
             cout << input[i] << "\t";
        }
        cout << "}\n";
    }
}

int removeDuplicates(vector<int> &nums) {

    print_vector(nums);
    int count = 0;

    for(int i = 1; i < nums.size(); i++) {

        if(nums[i - 1] == nums[i]) {
            count++;
        }



        if(count > 2) {
            count = 0;
        }



    }
    return 1;
}


int main(void) {

    vector<int> nums = {1, 1, 2, 2, 2, 2, 3, 4, 4, 5};

    removeDuplicates(nums);
    return 0;
}

