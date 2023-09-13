#include<iostream>
#include <valarray>
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

vector<int> merge(vector<int> leftVector, vector<int> rightVector, vector<int> mergedVector) {

    int l = 0;
    int r = 0;
    int m = 0;

    while((l < leftVector.size()) && (r < rightVector.size())) {
        if(leftVector[l] <= rightVector[r]) {
            mergedVector[m] = leftVector[l];
            l++;
            m++;
        }
        else {
            mergedVector[m] = rightVector[r];
            r++;
            m++;
        }
    }

    while(l < leftVector.size()) {
        mergedVector[m] = leftVector[l];
        m++;
        l++;
    }

    while(r < rightVector.size()) {
        mergedVector[m] = rightVector[r];
        m++;
        r++;
    }

    print_vector(mergedVector);


    return mergedVector;

}


vector<int> mergeSort(vector<int> input) {

    print_vector(input);

    if(input.size() <= 1) {
        return input;
    }
    else {
        int mid = input.size()/2;
        auto left = input.begin();
        auto middle = input.begin() + mid;
        auto right = input.end();

        vector<int> leftVector(left, middle);
        vector<int> rightVector(middle, right);

        print_vector(leftVector);
        print_vector(rightVector);

        vector<int> resultLeft(leftVector.size()/2);
        vector<int> resultRight(rightVector.size()/2);
        resultLeft = mergeSort(leftVector);
        resultRight = mergeSort(rightVector);

        vector<int> mergedVector(input.size());

        return merge(resultLeft, resultRight, mergedVector);


        
    }

    // return input;

}


int main(void) {
    vector<int> input = {2, 8, 5, 3, 9, 4, 1};
    // vector<int> input = {3, 1, 0};
    input = mergeSort(input);

    cout << endl << "-----------------------------------------------------" << endl;
    print_vector(input);
    cout << endl;

    return 0;
}