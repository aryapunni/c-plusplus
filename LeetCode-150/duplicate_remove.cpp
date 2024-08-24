//Leet code problem 26
//Given an integer array nums sorted in non-decreasing order, 
//remove the duplicates in-place such that each unique element appears 
//only once. The relative order of the elements should be kept the same.
// Then return the number of unique elements in nums.
//Consider the number of unique elements of nums to be k, 
//to get accepted, you need to do the following things:
//Change the array nums such that the first k elements of nums 
//contain the unique elements in the order they were present in nums 
//initially. The remaining elements of nums are not important as well as
// the size of nums. Return k.

#include<iostream>
#include<vector>

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


int removeDuplicates(vector<int>& nums) {

    int index = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[index] != nums[i]) {
            nums[index + 1] = nums[i];
            index++;
            count++;
        }

    }
    print_vector(nums);
    cout << "count: " << count << endl;
    return count;
}

int main(void) {
    vector<int> nums = {1, 1, 2, 2, 2, 2, 3, 4, 4, 5};
    removeDuplicates(nums);
    return 0;
}