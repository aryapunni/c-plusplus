#include <cctype>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;

int binary_search(int target, vector<int> &nums) {

    int start = 0;
    int end = nums.size() - 1;
    int mid = (end + start)/2;

    // cout << start << " " << end << " " << mid << endl;

    
    while(start <= end) {

        mid = (end + start)/2;
        cout << start << " " << end << " " << mid << endl;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {

            start = mid + 1;

        }
        else if(nums[mid] > target) {
            end = mid - 1;

        }
        else {
            return mid;
        }
    }


    // return 1;

}

int searchInsert(vector<int>& nums, int target) {

    int index = binary_search(target, nums);

    cout << "index: " << index << endl;

    return 1;


}

int main(void) {

    vector<int> numbers = {1, 2, 3, 4, 6};

    int target = 1;

    searchInsert(numbers, target);

    return 0;
}

