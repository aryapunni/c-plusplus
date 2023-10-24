//Rotate Array - Given an array, 
//rotate the array to the right by k steps, where k is non-negative.
#include <algorithm>
#include <future>
#include<iostream>
#include <iterator>
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

vector<int> rightShift(vector<int> input) {

    int size = input.size();
    int end = size - 1;
    for(int i = end - 1; i >= 0; i--) {
        input[i + 1] = input[i];
    }
    print_vector(input);

    return input;
}


void reverseArray(vector<int>::iterator start,  vector<int>:: iterator end) {

    cout << *start << "\t" << *end << endl;
    auto start_new = start;
    auto end_new = end;

    while(start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
    
}


void rotateArrayeff(vector<int>& input, int rotation) {

    if(input.size() == 0) {
        return;
    }

    rotation = rotation % input.size();

    print_vector(input);

    reverseArray(input.begin(), input.end() - 1);

    cout << "complete reversal\n";

    print_vector(input);

    cout << "reverse initial part\n";
    reverseArray(input.begin(), input.begin() + (rotation - 1));
    print_vector(input);

    cout << "reverse latter part\n";
    reverseArray(input.begin() + rotation, input.end() - 1);
    print_vector(input);


}


vector<int> rotateArray(vector<int> input, int rotation) {

    int size = input.size();
    int end = size - 1;
    rotation = rotation % size;
    vector<int> slice(rotation);

    copy(input.end() - rotation, input.end(), slice.begin());
    print_vector(slice);


    for(int i = 0; i < rotation; i++) {

        input = rightShift(input);

    }

    for(int j = 0; j < rotation; j++) {
        input[j] = slice[j];
    }


    return input;
}


int main(void) {

    vector<int> input = {};
    // vector<int> input = {1};
    // vector<int> input = {1, 2};
    // vector<int> input = {1, 2, 3, 4, 5, 6};

    rotateArrayeff(input, 1);


    cout << endl << "---------------------------------" << endl;
    print_vector(input);



    return 0;
}