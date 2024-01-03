#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iterator>
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



int binary_search(int target, vector<int> &nums) {

    int start = 0;
    int end = nums.size() - 1;
    int mid = (end + start)/2;

    // cout << start << " " << end << " " << mid << endl;

    
    while(start <= end) {

        mid = (end + start)/2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {

            start = mid + 1;

        }
        else if(nums[mid] > target) {
            end = mid - 1;

        }
        
    }

    if(nums[mid] < target) {
        return mid + 1;
    }


    return mid;

}

int searchInsert(vector<int>& nums, int target) {

    int index = binary_search(target, nums);

    if(nums[index] == target) {
        return index;
    }
    else {

        nums.insert(nums.begin() + index, target);
        return index;
    }


    return index;


}

int main(void) {

    vector<int> numbers = {1, 3, 5, 8, 12};

    for(int target = -1; target <= 15; target++) {

        searchInsert(numbers, target);
        print_vector(numbers);
    }



    return 0;
}

