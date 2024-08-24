//You are given an integer array nums consisting of n elements, 
//and an integer k.
//Find a contiguous sub array whose length is equal to k 
//that has the maximum average value and return this value. 
//Any answer with a calculation error less than 10-5 will be accepted.


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


double findSubArray(vector<int> input, int k) {

    int endWindow = 0;
    int startWindow = 0;
    double windowSum = 0;
    double maxAvg = -10000;
    int slide = 0;

    for(endWindow = 0; endWindow < input.size(); endWindow++) {

        windowSum += (double)input[endWindow];

        cout << "windowSum: " << windowSum << endl;
        
        slide++;

        if(slide == k) {

            cout << "sliding window finished\n Sum : " << windowSum << " average: " << windowSum/(double)k << endl;

            if(windowSum/(double)k > maxAvg) {
                cout << "max average is smaller" << endl;
                maxAvg = windowSum/(double)k;
                
            }

            slide--;
            windowSum = windowSum - (double)input[startWindow];
            startWindow++;

        }

    }
    return maxAvg;

}

int main(void) {

    // vector<int> input = {1,12,-5,-6,50,3};
    vector<int> input = {-1};

    double output = findSubArray(input, 1);
    print_vector(input);
    cout << "max average output: " << output << endl;

    return 0;
}