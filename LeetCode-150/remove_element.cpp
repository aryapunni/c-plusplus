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
    int count;

    int length = 0;
    int i = 0;
    int j = 0;

    while(i < nums.size()) {
        cout << "i: " << i << " j: " << j << "\tnums[i]: " << nums[i] << "\tnums[j]: " << nums[j] << endl;
        if(nums[i] == val) {
            while(nums[j] == val && j < nums.size() - 1) {
                j++;
            }
            cout << "Found the nums[j] "<< j << " which is not equal to value: "<< nums[j] << " nums[i] " << nums[i] << endl;

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j = i;

        }
        else {
            count++;
            i++;
            j = i;
        }
        
    }
    cout << "count: \t" <<  nums.size() - (count + 1) << endl;
    print_vector(nums);


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