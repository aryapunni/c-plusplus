#include <algorithm>
#include <iostream>

#include <vector>
using namespace std;

class Output {
    private:
        int first;
        int second;

    public:

        Output() {}

        Output(int a, int b)
        {
            first = a;
            second = b;
        }

        Output(const Output &out) {
            first = out.first;
            second = out.second;
        }

        int operator ==(Output out) {
            if((first == out.first) && (second == out.second)) {
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


ostream & operator << (ostream &out, const Output &o)
{
    out << "(" << o.first << ", " << o.second << ")";
    return out;
}


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


class TestCase {
    public: 
        Input input;
        Output output;

        TestCase(Input in, Output out) {
            input = in;
            output = out;
        }

};


int minimum(int a, int b) {
    if(a < b) {
        return a;
    }
    else {
        return b;
    }
}


Output max_water(vector<int> water_volumes)
{
    Output out = Output(1, 1);
    int length = water_volumes.size();
    int end = length - 1;
    int i = 0, j = end;
    int area = 0;
    int max_area = 0;
    

    while(i < j) {

        area = (j - i) * minimum(water_volumes[j], water_volumes[i]);
        cout << "bottom\t" << (j - i) << "\thight\t" << minimum(water_volumes[j], water_volumes[i]) << "\tarea\t" << area << "\tmaximum area\t" << max_area << endl;

        if(max_area < area) {
            max_area = area;
            out = Output(i , j);
        }

        if(water_volumes[j] <= water_volumes[i]) {
            j--;
        }
        else {
            i++;
        }
        

    }

    return out;
}


int main()
{
    vector<int> array {2, 4, 8, 4, 4, 9};

    vector<TestCase> test_cases {TestCase(Input(array), Output(2, 5))};


    // TestCase tc1;
    // Output out1;
    // out1.first = 8;
    // out1.second = 9;

    // tc1.input = vector<int>{2, 4, 8, 4, 4, 9};
    // tc1.output = out1;
    // test_cases.push_back(tc1);


    for (TestCase tc: test_cases) {
        
        Output actual_output = max_water(tc.input.get());
        if (actual_output != tc.output) {
            
            cout << "For input ";
            cout << tc.input;
            cout << ", expected " << tc.output;
            cout << ", got " << actual_output;
            cout << endl;
        }
    }
    return 0;
    
}