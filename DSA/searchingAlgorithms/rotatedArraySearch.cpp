#include <iostream>
#include <vector>

using namespace std;




int binarySearchRecursion(int targetValue, vector<int> input, int startIndex, int endIndex, int check) {

    int middle = 0;
    check++;
    cout << "check\t" << check << endl;

    if(startIndex > endIndex) {

        cout << "start index: \t" << startIndex << "\tend index\t" << endIndex << "\tmiddle\t" << middle << endl;
        return -1;
    }
    else if (startIndex <= endIndex) {

        middle = startIndex + (endIndex - startIndex)/2;

        cout << "start index: \t" << startIndex << "\tend index\t" << endIndex << "\tmiddle\t" << middle << endl;

        if(input[middle] == targetValue) {

            cout << "Found the value\t" << "input[" << middle << "] = " << input[middle] << endl;

            return middle;
        }   
        else {
            if(input[middle] < targetValue) {

                cout << "Target value is greater than middle value" << endl;
                int startIndex_prev = startIndex;
                startIndex = middle + 1;
                cout << "start Index changed from " << startIndex_prev << " to " << startIndex << endl;
                cout << "end index is: " << endIndex << endl;
                return binarySearchRecursion(targetValue, input, startIndex, endIndex, check);
            }
            else {

                cout << "Target value is lesser than middle value" << endl;
                int endIndex_prev = endIndex;
                endIndex = middle - 1;
                cout << "end index changed from " << endIndex_prev << " to " << endIndex << endl;
                cout << "start index is: " << startIndex << endl;
                return binarySearchRecursion(targetValue, input, startIndex, endIndex, check);
            }
        }

    }
   return -1;

}



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

void reverseArray(vector<int>::iterator start,  vector<int>:: iterator end) {

    cout << *start << "\t" << *end << endl;
    auto start_new = start;
    auto end_new = end;

    while(start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
    
}


void rotateArray(vector<int>& input, int rotation) {

    if(input.size() == 0) {
        return;
    }

    // rotation = rotation % input.size();

    print_vector(input);

    reverseArray(input.begin(), input.end() - 1);

    cout << "complete reversal\n";

    print_vector(input);

    cout << "reverse initial part\n";
    reverseArray(input.begin(), input.end() - (rotation + 1));
    print_vector(input);

    cout << "reverse latter part\n";
    reverseArray((input.begin()) + (rotation + 2), input.end() - 1);
    print_vector(input);


}



int rotatedVectorFastSearchRecursion(vector<int> input, int targetValue, int startIndex, int endIndex) {

    print_vector(input);
    cout << "startIndex:  " << startIndex << "  endIndex  " << endIndex << endl;

    if(startIndex > endIndex) {
        return -1;
    }
    else {
        int mid = startIndex + (endIndex - startIndex)/2;
        cout << "startIndex:  " << startIndex << "  endIndex  " << endIndex << "  mid  " << mid << endl;
        if(input[mid] == targetValue) {
            return mid;
        }
        else {
            
            if(input[mid] >= input[startIndex]) {
                cout << "left sorted" << endl;

                if((input[mid] > targetValue) && (input[startIndex] <= targetValue)) {

                    endIndex = mid - 1;
                    return rotatedVectorFastSearchRecursion(input, targetValue, startIndex, endIndex);

                }
                else {
                    startIndex = mid + 1;
                    return rotatedVectorFastSearchRecursion(input, targetValue, startIndex, endIndex);
                }
            }
            else {

                cout << "right sorted" << endl;
                if((input[mid] < targetValue) && (targetValue < input[endIndex])) {

                    startIndex = mid + 1;
                    return rotatedVectorFastSearchRecursion(input, targetValue, startIndex, endIndex);

                }
                else {
                    endIndex = mid - 1;
                    return rotatedVectorFastSearchRecursion(input, targetValue, startIndex, endIndex);
                }

            }
            
        }
    }
    return -1;
}



int rotatedVectorFastSearch(vector<int> input, int targetValue) {

    print_vector(input);

    int length = input.size();
    int end = length - 1;
    if(input[end] > input[0]) {

        return binarySearchRecursion(targetValue, input, input[0], input[end], 0);

    }
    else {
        int startIndex = 0;
        int endIndex = end;
        int mid = startIndex + (endIndex - startIndex)/2;

        while(startIndex <= endIndex) {
            mid = startIndex + (endIndex - startIndex)/2;

            cout << "startIndex:  " << startIndex << "  endIndex  " << endIndex << "  mid  " << mid << endl;

            if(input[mid] == targetValue) {

                cout << "Found the value  " << input[mid] << "  is in  " << mid << endl;

                return mid;

            }
            else if(input[mid] >= input[startIndex]) {

                if((targetValue < input[mid]) && (input[startIndex] <= targetValue)) {
                    cout << "value is in the sorted left session" << endl;
                    endIndex = mid - 1;

                }
                else {
                    cout << "Value is in the unsorted right session" << endl;
                    startIndex = mid + 1;
                }

            }
            else {
                if((targetValue > input[mid]) && (targetValue <= input[endIndex])) {
                    cout << "Value is in right session" << endl;
                    startIndex = mid + 1;

                }
                else {
                    endIndex = mid - 1;
                    cout << "Value is in left session" << endl;
                }
            }  
        }
    }
    return -1;
}


int findAxis(vector<int> input) {
    int length = input.size();
    int end = length - 1;

    if(input[end] > input[0]) {
        return 0;
    }
    else {
        for(int i = 0; i < end; i++) {
            if(input[i] > input[i + 1]) {
                return i + 1;
            }
        }
    }
    return -1;
}

int rotatedVectorSearch(vector<int> input, int targetValue) {

    int axis = findAxis(input);
    int targetIndex = 0;
    cout << "axis: " << axis << endl;

    rotateArray(input, axis);
    print_vector(input);
    targetIndex = binarySearchRecursion(targetValue, input, 0, input.size() - 1, 0);


    
    return targetIndex;
}

int main(void) {
    vector<int> input = {6, 7, 8, 1, 2, 3, 4, 5};
    // vector<int> input = {8, 1, 2, 3, 4, 5, 6, 7};
    int targetValue = 8;
    int end = input.size() - 1;

    int result = rotatedVectorFastSearchRecursion(input, targetValue, 0, end);

    cout << endl << "-------------------------------------" << endl;
    cout << "Result: " << result << endl;
    return 0;
}