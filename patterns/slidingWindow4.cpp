//Given an array of positive numbers and a positive number ‘S’, 
//find the length of the smallest contiguous sub array 
//whose sum is greater than or equal to ‘S’. 
//Return 0, if no such sub array exists.


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


int main(void) {

    return 0;
}

