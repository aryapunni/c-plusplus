//Leet code - 1343 Given an array of integers arr and two integers k and threshold, 
//return the number of sub-arrays of size k and average greater than 
//or equal to threshold.



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


class slidingWindow{
    public:
        static int averageSlidingWindow(vector<int>& arr, int k, int threshold) {
            int windowSum = 0;
            int start = 0;
            int i = 0;
            int result = 0;

            for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {

                windowSum += arr[windowEnd];

                //cout << "k: " << k << " windowSum: " << windowSum << endl;
                i++;

                if(i == k) {

                    //cout << "windowSum: " << windowSum << " k: " << k << endl;
                    i--;
                    if(windowSum/k >= threshold) {
                        result++;
                    }
                    

                    //cout << "windowSum/size: " << windowSum/size << endl;
                    windowSum = windowSum - arr[start];

                    //cout << "windowSum after subtracting start value: " << windowSum << endl;
                    start++;
                }

            }

            return result;
        
    }
        
};


int main(void) {

    vector<int> input = {1, 3, 2, 6, -1, 4, 1, 8, 2};

    int result = slidingWindow :: averageSlidingWindow(input, 5, 2);

    cout << "result: " << result << endl;


    return 0;
}

