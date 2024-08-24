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


void bubbleSort(vector<int> &input) {

    print_vector(input);
    int size = input.size();
    int endIndex = size - 1;
    bool swapstat = false;

    for(int i = 0; i < endIndex; i++) {

        for(int j = 0; j < endIndex - i; j++)
        {
            cout << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "i: \t" << i << "\txxxxxxxxxxxxxxxx" << "\tj: \t" << j << endl;
            print_vector(input);
            if(input[j + 1] < input[j])
            {
                swapval(&input[j + 1], &input[j]);
                swapstat = true;
            }


        }
        if(swapstat == false) {
            break;
        }
    }

}

int main(void) {
    vector<int> input = {2, 8, 5, 3, 9, 4, 1};
    bubbleSort(input);

    cout << endl << "-----------------------------------------------------" << endl;
    print_vector(input);
    return 0;
}