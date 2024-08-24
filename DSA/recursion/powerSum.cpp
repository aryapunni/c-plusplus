#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class MultiType{
    public:
        int type;
        int integer;
        vector<int> int_val;
    
    MultiType(int intgr) {

        type = 0;
        integer = intgr;
    }

    MultiType(vector<int> values) {
        type = 1;
        int_val = values;
    }


};


void print_vector(vector<int> input) {
    if(input.empty()) {
        cout << "{}";
    }
    else {
        cout << "{\t";
        for(int i = 0; i < input.size(); i++) {
             cout << input[i] << ",\t";
        }
        cout << "}\n";
    }
}

int vectPowersum(vector<int> input) {

    int result = 0;

    for(int i = 0; i < input.size(); i++) {
        result = result + input[i];
    }

    result = round(pow(result, input.size()));
    return result;

}

int power_Sum(vector<MultiType> input) {

    int result = 0;
    for(int i = 0; i < input.size(); i++) {
        if(input[i].type == 0) {
            cout << "input is an integer: \t" << input[i].integer << "\n";
            result = result + input[i].integer;
        }
        else if (input[i].type == 1) {

            cout << "input is a vector" << "\n";
            print_vector(input[i].int_val);
            MultiType newVect = MultiType(input[i].int_val); 
            result = result + power_Sum(newVect));
        
        }
    }

    cout << "result: \t" << result << "\n"; 
    return 0;

}

int main(void) {

    vector<MultiType> input = {MultiType(4), MultiType(3), MultiType({4, 1, 2})};
    // vector<MultiType> input_1 = {MultiType(1), MultiType(2), MultiType({4, MultiType({4, 1, 2}), 1, 2})};
    power_Sum(input);

    return 0;
}