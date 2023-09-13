#include<iostream>
#include<vector>

using namespace std;

bool isMonotonic(vector<int> input) {
    bool result = false;
    int size = input.size();
    int end = size - 1;

    if(size < 2) {
        return true;
    }

    if(input[0] > input[end]) {

        for(int i = 0; i < size - 1; i++) {
            if(input[i] < input[i + 1]) {
                result = false;
                break;
            }
            else {
                result = true;
            }
            
        }
    }
    else if (input[0] < input[end]) {

        for(int i = 0; i < size - 1; i++) {
            if(input[i] > input[i + 1]) {
                result = false;
                break;
            }
            else {
                result = true;
            }
            
        }
    
    }
    else {
        for(int i = 0; i < size - 1; i++) {
            if(input[i] != input[i + 1]) {
                result = false;
                break;
            }
            else {
                result = true;
            }
            
        }
    }
    return result;
}

int main(void) {
    // vector<int> input = {3, 2, 1};
    // vector<int> input = {1, 2, 2};

    // vector<int> input = {3, 3, 3};
    // vector<int> input = {7};
    // vector<int> input = {};
    vector<int> input = {2, 2, 3, 1};


    bool result = isMonotonic(input);

    cout << endl << "---------------------------------" << endl;
    if(result == true) {
        cout << "Input is Monotonic" << endl;
    }
    else {
        cout << "Input is not Monotonic" << endl;
    }
    return 0;
}