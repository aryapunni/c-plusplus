
//Question 1: Sorted Squared Array - You are given an array of Integers 
//in which each subsequent value is not less than the previous value. 
//Write a function that takes this array as an input and 
//returns a new array with the squares of each number 
//sorted in ascending order.

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


vector<int> squareArray(vector<int> input) {

    int size = input.size();
    int end = size - 1;
    int i = 0, j = end, k = end;
    vector<int> resultVector(size);

    while(i <= j && k >= 0) {
        cout << input[i] << "\t" << input[j] << endl;
        int squareI = input[i] * input[i];
        int squareJ = input[j] * input[j];

        if(squareI > squareJ) {
            resultVector[k] = squareI;
            k--;
            i++;
            cout << "Square I is greater than Square J" << endl;

        }
        else if (squareJ > squareI) {
            resultVector[k] = squareJ;
            j--;
            k--;
            cout << "Square J is greater than Square I" << endl;
        }
        else if (squareI == squareJ) {

            cout << "Square I is equal to Square J" << endl;
            if(i == j) {
                resultVector[k] = squareI;
                cout << "\tI is equal to J" << endl;
                break;
            }
            else {
                cout << "\tI is not equal to J" << endl;
                resultVector[k] = squareI;
                k--;
                resultVector[k] = squareJ;
                k--;
                i++;
                j--;
            }
        
        }
        
    }

    print_vector(input);
    return resultVector;
}

int main(void) {

    // vector<int> input = {-3, -1, 0, 1, 2};
    // vector<int> input = {1, 3, 5};
    // vector<int> input = {0, 5, 6};
    vector<int> input = {-4, -2, 0, 1};

    input = squareArray(input);

    cout << endl << "------------------------------------------------" << endl;

    print_vector(input);



    return 0;
}