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


void swapval(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    
}


void insertionSort(vector<int> &input) {

    print_vector(input);

    int size = input.size();
    int endIndex = size - 1;

    for(int i = 1; i <= endIndex; i++) {
        int j = i - 1;

        while((j >= 0) && (input[j + 1] < input[j])) {
            swapval(&input[j], &input[j + 1]);
            j--;
        }
    }

}


int main(void) {
    vector<int> input = {2, 8, 5, 3, 9, 4, 1};
    insertionSort(input);

    cout << endl << "-----------------------------------------------------" << endl;
    print_vector(input);

    return 0;
}