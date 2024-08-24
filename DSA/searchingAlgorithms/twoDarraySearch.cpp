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



void print2Dvector(vector<vector<int>> input) {
    int row = input.size();
    int rowItem = 0;
    if(row != 0) {
        rowItem = input[0].size();
    }

    cout << "row: " << row << " rowItem " << rowItem << endl;

    for(int i = 0; i < row; i++) {
        print_vector(input[i]);
    }

}

int binarySearch(vector<int> input, int targetValue, int startIndex, int endIndex) {

    if(startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex)/2;

        if(input[mid] == targetValue) {
            return mid;
        }
        else if (input[mid] > targetValue) {

            endIndex = mid - 1;
            return binarySearch(input, targetValue, startIndex, endIndex);
        
        }
        else {
            startIndex = mid + 1;
            return binarySearch(input, targetValue, startIndex, endIndex);
        }
    }
    return -1;
}


int findRow(vector<vector<int>> input, int targetValue, int start, int end) {
    if(start <= end) {
        int mid = start + (end - start)/2;
        if((input[mid][0] <= targetValue) && (input[mid][input[mid].size() - 1] >= targetValue)) {
            return mid;
        }
        else if(input[mid][0] > targetValue) {
            end = mid - 1;
            return findRow(input, targetValue, start, end);
        }
        else {
            start = mid + 1;
            return findRow(input, targetValue, start, end);

        }
    }
    return -1;
}

bool twoDVectorSearch(vector<vector<int>> input, int targetValue, int rows, int rowItems) {

    int targetIndex = -1;
    int row = findRow(input, targetValue, 0, rows - 1);
    if(row == -1) {
        return false;
    }
    else {

        cout << "row in which the " << targetValue << " is in: " << row << endl;

        targetIndex = binarySearch(input[row], targetValue, 0, input[row].size() - 1);
        if (targetIndex == -1) {
            return false;
        
        }
        else {
            cout << targetValue << " is in index: " << targetIndex << endl;
            return true;
        }

    }
    return false;
}

int main(void) {

    vector<vector<int>> input {
        {1, 3, 5, 7}, 
        {10, 11, 16, 20}, 
        {23, 30, 34, 60}
    };

    int targetValue = 60;
    int rows = input.size();
    int rowItems = 0;
    if(rows != 0) {
        rowItems = input[0].size();
    }

    print2Dvector(input);
    bool result = twoDVectorSearch(input, targetValue, rows, rowItems);
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "result: " << result << endl;
    return 0;
}