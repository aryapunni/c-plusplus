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
             cout << input[i] << "\t";
        }
        cout << "}\n";
    }
}



int findLeftExtreme(vector<int> input, int targetValue, int startIndex, int endIndex) {
    int start = -1;

    if(startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex)/2;

        if(input[mid] == targetValue) {
            cout << "found the value" << endl;
            if(mid == 0) {
                return 0;
            }
            else {
                if(input[mid - 1] != targetValue) {
                    return mid;
                }
                else {
                    endIndex = mid - 1;
                    start = findLeftExtreme(input, targetValue, startIndex, endIndex);
                    return start;
                }
            }
        }
        else if(input[mid] > targetValue) {
            endIndex = mid - 1;
            start = findLeftExtreme(input, targetValue, startIndex, endIndex);
            return start;
        }
        else {
            startIndex = mid + 1;
            start = findLeftExtreme(input, targetValue, startIndex, endIndex);
            return start;
        }
    }
    return start;
}


int findRightExtreme(vector<int> input, int targetValue, int startIndex, int endIndex) {
    int end = -1;

    if(startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex)/2;

        if(input[mid] == targetValue) {
            cout << "found the value" << endl;
            if(mid == input.size() - 1) {
                return input.size() - 1;
            }
            else {
                if(input[mid + 1] != targetValue) {
                    return mid;
                }
                else {
                    startIndex = mid + 1;
                    end = findRightExtreme(input, targetValue, startIndex, endIndex);
                    return end;
                }
            }
        }
        else if(input[mid] > targetValue) {
            endIndex = mid - 1;
            end = findRightExtreme(input, targetValue, startIndex, endIndex);
            return end;
        }
        else {
            startIndex = mid + 1;
            end = findRightExtreme(input, targetValue, startIndex, endIndex);
            return end;
        }
    }

    return end;
}


vector<int> findExtremes(vector<int> input, int targetValue, int startIndex, int endIndex) {
    int start = -1;
    int end = -1;

    start = findLeftExtreme(input, targetValue, startIndex, endIndex);
    end = findRightExtreme(input, targetValue, startIndex, endIndex);

    print_vector({start, end});

    return {start, end};
}



int main(void) {
    // vector<int> input = {1, 2, 2, 2, 3};
    vector<int> input = {0, 1, 1 , 1, 2, 2, 2, 3, 3, 4, 5, 5, 6, 7};
    int end = input.size() - 1;
    vector<int> result = findExtremes(input, 8, 0, end);

    cout << endl << "-----------------------------------------------" << endl;
    print_vector(input);
    print_vector(result);
    cout << endl; 
    return 0;
}