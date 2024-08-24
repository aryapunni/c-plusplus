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


void selectionSort(vector<int> &input) {

    print_vector(input);

    int size = input.size();
    int endIndex = size - 1;
    int minval = 0;
    int minIndex = 0;

    for(int i = 0; i < endIndex; i++) {

        minval = input[i];
        minIndex = i;

        for(int j = i + 1; j <= endIndex; j++) { 
            cout << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "i: \t" << i << "\txxxxxxxxxxxxxxxx" << "\tj: \t" << j << endl;
            print_vector(input);

            cout << "current minvalue is: " << minval << " input[i]: " << input[i] << " min Index is: " << minIndex << endl;
            if(input[j] < minval) {
                minval = input[j];
                minIndex = j;
                
                cout << "Values changes here...." << endl << "min Value is: " << minval << " input[i]: " << input[i] << " min Index is: " << minIndex << endl;
            }

        }

        swapval(&input[i], &input[minIndex]);
    }

}


int main(void) {
    vector<int> input = {2, 8, 5, 3, 9, 4, 1};
    selectionSort(input);

    cout << endl << "-----------------------------------------------------" << endl;
    print_vector(input);

    return 0;
}