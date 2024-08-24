#include<iostream>
#include<vector>

using namespace std;


void print_vector(vector<double> input) {
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
        static vector<double> averageSlidingWindow(vector<double> input, double size) {
            vector<double> averageVector;

            
            double end = 0;
            double windowSum = 0;
            double start = 0;
            int k = 0;

            for(int windowEnd = 0; windowEnd < input.size(); windowEnd++) {

                windowSum += input[windowEnd];

                cout << "k: " << k << " windowSum: " << windowSum << endl;
                k++;

                if(k == size) {

                    cout << "windowSum: " << windowSum << " k: " << k << endl;
                    k--;
                    averageVector.push_back(windowSum/size);

                    cout << "windowSum/size: " << windowSum/size << endl;
                    windowSum = windowSum - input[start];

                    cout << "windowSum after subtracting start value: " << windowSum << endl;
                    start++;
                }

            }

            return averageVector;
        }
};


int main(void) {

    vector<double> input = {1, 3, 2, 6, -1, 4, 1, 8, 2};

    vector<double> result = slidingWindow :: averageSlidingWindow(input, 5);

    print_vector(result);


    return 0;
}

