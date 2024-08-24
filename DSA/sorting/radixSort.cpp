#include<iostream>
#include<vector>
#include <cmath>

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

int maxValue(vector<int> input) {
    int max = input[0];

    for(int i = 0; i < input.size(); i++) {
        if(max < input[i]) {
            max = input[i];
        }
    }
    return max;
}

int findExponent(int value) {
    int i = 0;
    for(i = 1; value/i > 0; i*=10) {

        cout << "value: " << value << " i: " << i << endl;
    
    }

    return i/10;
}

void swapval(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    
}


void countSort(vector<int> &input, int exp, int size) {

    const int max = 10;
    vector<int> output(size);
    vector<int> count(max, 0);

    for(int i = 0; i < size; i++) {
        count[input[i]/exp % 10]++;
    }

    print_vector(count);

    for(int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    print_vector(count);

    for(int i = size - 1; i >= 0; i--) {

        int place = (input[i] / exp) % 10;

        output[count[place] - 1] = input[i];
        count[place]--;

    }

    print_vector(output);

    for(int i = 0; i < size; i++) {
        input[i] = output[i];
    }

    print_vector(input);
}

void radixSort(vector<int> &input) {

    int size = input.size();

    print_vector(input);


    int maxVal = maxValue(input);
    cout << "maximum Value: " << maxVal << endl;


    for(int i = 1; maxVal/i; i*=10) {
        countSort(input, i, size);
    }


}

int main(void) {
    vector<int> input = {2, 8, 5, 3, 9, 4, 1};
    vector<int> input2 = {170, 45, 75, 90, 802, 24, 2, 66};
    vector<int> input3 = {170, 90, 802, 45, 2, 75};
    radixSort(input3);

    cout << endl << "-----------------------------------------------------" << endl;
    print_vector(input2);
    return 0;
}