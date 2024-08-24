#include <iostream>
#include <vector>
using namespace std;


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

vector< vector<int> > numPos(vector<int> input, int num)
{
    vector<vector<int>> vectorOfvectors;
    vector<int> copy;
    for(int i = 0; i <= input.size(); i++) {
        copy = input;
        copy.emplace(copy.begin() + i, num);
        vectorOfvectors.push_back(copy);
    }
    return vectorOfvectors;
}

vector<vector <int>> permutations(vector <int> input) {

    vector<vector<int>> vectorofvectors {{}};
    vector<vector<int>> vectorofpermutations {{}};
    vector<vector<int>> vectorofresultants;

    if(input.size() == 1) {
        return vector<vector <int>> {input}; 
    }
    else {
        //save first element
        int first_digit = input[0];

        // Remove first digit and create a new vector
        vector<int> new_vec = input;
        new_vec.erase(new_vec.begin());


        vectorofvectors = permutations(new_vec);


        //iterate through all returned vectors and

        for(int i = 0; i < vectorofvectors.size(); i++) {
            
            // print_vector(vectorofvectors[i]);
            cout << endl;


            vectorofpermutations = numPos(vectorofvectors[i], first_digit);



            for(int j = 0; j < vectorofpermutations.size(); j++) {
                vectorofresultants.push_back(vectorofpermutations[j]);
            }

        } 

        cout << "size of resultants: \t" << vectorofresultants.size() << "\nvector of resultants: \n";
        for(int k = 0; k < vectorofresultants.size(); k++) {
            print_vector(vectorofresultants[k]);
            cout << endl;


        }


    }


    return vectorofresultants;
}

int main(void) {


    vector<int> array {1, 2, 3, 4};

    vector<vector<int>> result = permutations(array);

    // vector<vector<int>> res = numPos(array, 3);

    // for(int i = -1; i < res.size(); i++) {
    //     print_vector(res[i]);
    // }
    cout << endl;
    cout << endl;
    cout << "-----------------------------------------";
    cout << endl;
    cout << "vectors are: \n";

    for(int i = 0; i < result.size(); i++) {

        print_vector(result[i]);
    }

    cout << endl;

    return 0;
}