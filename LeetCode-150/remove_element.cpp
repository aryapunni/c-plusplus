#include<iostream>
#include <type_traits>
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

int removeElement(vector<int>& nums, int val) {
    int count = 0;
    int i = 0;
    int j = 0;

    while(i < nums.size()) {
        if(nums[i] != val) {
            nums[j] = nums[i];
            j++;
            count++;
        }
        i++;

       
    }

    cout << "nums.size() : " << nums.size() << endl;
    print_vector(nums);
    cout << count << endl;
    return count;
}

int main(void) {

    // vector<int> nums = {3, 2, 2, 3};
    // int val = 3;
    // removeElement(nums, val);
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    removeElement(nums, val);
    return 0;
}