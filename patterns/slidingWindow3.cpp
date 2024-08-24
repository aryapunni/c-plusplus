//Given an array of positive numbers and a positive number ‘k’, 
//find the maximum sum of any contiguous subarray of size ‘k’.

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


vector<int> findSubArray(vector<int> input, int k) {
    vector<int> output(k);

    int endWindow = 0;
    int startWindow = 0;
    int windowSum = 0;
    int maxSum = 0;
    int slide = 0;

    for(endWindow = 0; endWindow < input.size(); endWindow++) {

        windowSum = input[endWindow];
        
        slide++;

        if(slide == k) {

            if(windowSum > maxSum) {
                maxSum = windowSum;
                output.clear();
                for(int i = startWindow; i <= endWindow; i++) {
                    output.push_back(input[i]);
                }

            }

            slide--;
            windowSum = windowSum - input[startWindow];
            startWindow++;

        }


    }
    print_vector(output);
    return output;


}

int main(void) {

    vector<int> input = {1, 2, 4, 5, 6, 7, 3};

    vector<int> output = findSubArray(input, 3);
    print_vector(input);
    print_vector(output);

    return 0;
}