#include <vector>
#include <iostream>
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

void print_powerset(vector<vector<int>> input) {
    for(int i = 0; i < input.size(); i++) {
        print_vector(input[i]);
    }
    cout << endl;
}

vector<vector<int>> powerset(vector<int> input) {

    vector<vector<int>> powersetVector = {};
    vector<vector<int>> resultVector = {};
    vector<int> copyVect;

    if(input.size() == 0) {

        return {{}};
    }
    else {

        int first_digit = input[0];

        vector<int> lessInput = input;

        lessInput.erase(lessInput.begin());

        resultVector = powerset(lessInput);

        for(int i = 0; i < resultVector.size(); i++) {

            copyVect = resultVector[i];

            powersetVector.push_back(copyVect);
            copyVect.push_back(first_digit);
            powersetVector.push_back(copyVect);

        }


        return powersetVector;

    }
}

int main(void) {

    vector<int> input = {1, 2};

    vector<vector<int>> result = powerset(input);

    cout << "----------------output--------------------";
    cout << endl;

    print_powerset(result);

    return 0;
}