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

int minSubArray(vector<int> input, int k) {
    
    int startWindow = 0;
    int endWindow = 0;
    int slide = 0;
    vector<int> resultWindow;
    int windowLength = 0;
    int result = input.size();
    cout << result << endl;

    int windowSum = 0;

    for(endWindow = 0; endWindow < input.size(); endWindow++) {

        cout << result << " INPUT IS: " << input[endWindow]  << endl;

        if(input[endWindow] >= k) {
            result = 1;
            return result;
        }

        if(windowSum < k) {
            

            windowSum += input[endWindow];
            windowLength++;
            cout << "windowSum: " << windowSum << " windowLength: " << windowLength << endl;

        }

        if(windowSum >= k) {


            cout << "windowSum is greater than k: " << windowSum << " windowLength: " << windowLength << endl;
            windowSum = windowSum - input[startWindow];
            startWindow++;
            windowLength--;
            cout << "windowSum after slide: " << windowSum << " windowLength: " << windowLength << endl;

            if(result > windowLength) {
                result = windowLength;
            }
 
        }

       cout << "result: " << result << endl;


    }
    return result;
}


int main(void) {

    vector<int> input = {1, 2, 3, 5, 2};

    int result = minSubArray(input, 8);

    cout << "result: " << result << endl;



    return 0;
}

