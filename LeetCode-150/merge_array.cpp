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



void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int length = m + n;
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    cout << nums1.size() << endl;

    if(nums1.size() == 0){
        for(int i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
            print_vector(nums1);
        }
        // return;
    }
    else if(nums2.size() == 0) {
        return;
    }

    while(i >= 0) {

        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

    }
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    print_vector(nums1);
        
}


int main(void){

    // vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums1 = {0};
    // vector<int> nums2 = {5, 6, 7};
    vector<int> nums2 = {1};
    int n = nums2.size();
    int m = nums1.size() - n;

    merge(nums1, m, nums2, n);
    return 0;
}