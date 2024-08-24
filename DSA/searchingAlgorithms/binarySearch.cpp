#include<iostream>
#include<vector>

using namespace std;

// Input pattern class
class Input {
    private:
        vector<int> input;

    public:
        Input() {}

        Input(vector<int> vec) {
            input = vec;
        }

        Input(int *array, int len) {
            for(int i = 0; i < len; i++) {
                input.push_back(array[i]);
            }
        }

        Input(const Input &in) {
            input = in.input;
        }

        vector<int> get() const {
            return input;
        }
        
};

ostream & operator << (ostream &out, const Input &in)
{
    out << "{";

    if (in.get().empty()) {
        out << "}";
        return out;
    }

    int size = in.get().size();
    for (int i = 0; i < size - 1; i++)
    {
        out << in.get()[i] << ", ";
    }
    out << in.get().back();

    out << "} ";

    return out;
}


// Ountput pattern class
class Output {
    private:
        int index;


    public:

        Output() {}

        Output(int a)
        {
            index = a;
        }

        Output(const Output &out) {
            index = out.index;
        }

        int operator == (Output out) {
            if(index == out.index) {
                return 1;
            } else {
                return 0;
            }
        }

        int operator !=(Output out) {
            if(*this == out) {
                return 0;
            } else {
                return 1;
            }
        }

        friend ostream & operator << (ostream &out, const Output &o);

};


ostream & operator << (ostream &out, const Output &o)
{
    out << "(" << o.index << ")";
    return out;
}


class TestCase {
    public: 
        Input input;
        Output output;
        int target_value;

        TestCase(Input in, Output out, int tv) {
            input = in;
            output = out;
            target_value = tv;
        }

};


int binarySearchRecursion(int targetValue, vector<int> input, int startIndex, int endIndex) {

    int middle = 0;

    if(startIndex > endIndex) {

        return -1;
    }
    else if (startIndex <= endIndex) {

        middle = (endIndex + startIndex)/2;

        if(input[middle] == targetValue) {

            return middle;
        }   
        else {
            if(input[middle] < targetValue) {

                startIndex = middle + 1;
                return binarySearchRecursion(targetValue, input, startIndex, endIndex);
            }
            else {

                endIndex = middle - 1;
                return binarySearchRecursion(targetValue, input, startIndex, endIndex);
            }
        }

    }
   return -1;

}



int binarySearch(int targetValue, vector<int> input) {

    int startIndex = 0;
    int endIndex = input.size() - 1;
    int value = 0;
    int i = 0;
    int middle = (endIndex - startIndex)/2;

    while(startIndex <= endIndex) {

        middle = startIndex + (endIndex - startIndex)/2;
        cout << "start index: \t" << startIndex << "\tend index\t" << endIndex << "\tmiddle\t" << middle << endl;
        if(input[middle] == targetValue) {
            return middle;
        }
        else if (input[middle] > targetValue) {
            endIndex = middle - 1;

        }
        else if (input[middle] < targetValue) {

            startIndex = middle + 1;
        
        }

    }
    return -1;
}


int main(void) {

    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = binarySearchRecursion(-2, input, 0, input.size() - 1);

    cout << endl << "------------------------------------------" << endl;
    cout << "result\t" << result << endl;
    return 0;
}
