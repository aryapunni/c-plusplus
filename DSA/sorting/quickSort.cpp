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



void swapval(int *x, int *y) {

    cout << "x: " << *x << "\ty: " << *y << endl;
    int temp = *x;
    *x = *y;
    *y = temp;
    
}



int partition(int left, int right, vector<int> &input) {

    int i = 0;


    int pivot = input[right];
    i = left - 1;
        
    for(int j = left; j < right; j++) {

        if(input[j] < pivot) {
            i++;
            swapval(&input[j], &input[i]);
        }
    }

    i++;
    swapval(&input[i], &input[right]);

    
    return i;
}


void quickSort(vector<int> &input, int left, int right) {

    print_vector(input);

    if(right <= left) {
        return;
    } 

    int pivotLoc = partition(left, right, input);

    quickSort(input, left, pivotLoc - 1);
    quickSort(input, pivotLoc + 1, right);

}


int main(void) {
    vector<int> input = {2, 8, 5, 3, 9, 4, 1};
    // vector<int> input = {3, 1, 0};
    quickSort(input, 0, input.size() - 1);

    cout << endl << "-----------------------------------------------------" << endl;
    print_vector(input);
    cout << endl;

    return 0;
}