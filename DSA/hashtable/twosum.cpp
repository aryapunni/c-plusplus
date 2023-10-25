//Leet code Question 1: Given an array of integers nums and an integer target, 
//return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, 
//and you may not use the same element twice.
//You can return the answer in any order.

#include <iostream>

#include <vector>
#include <map>
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
        int target_value;

        TestCase(Input in, Output out, int tv) {
            input = in;
            output = out;
            target_value = tv;
        }

};

void print_map(map<int, int> test) {
    map<int, int>::iterator itr; 
    for(itr = test.begin(); itr != test.end(); ++itr) {
        cout << "\t" << itr->first << "\t" << itr->second <<"\n";
    }
    cout << endl;
}

Output two_sum_mtwo(vector<int> int_var, int target_value) {

    Output out = Output(0, 0);
    std::map<int, int> tv;

    if(int_var.empty()) {
        out = Output(0, 0);
        return out;
    }
    else if(int_var.size() == 1) {
        out = Output(0, 0);
        return out;
    }
    else if(int_var.size() == 2) {
        auto sum = int_var[0] + int_var[1];
        if(sum == target_value) {
            out = Output(0, 1);
        }
        else {
            out = Output(0, 0);
        }
        return out;
    }
    else {
        for(int i = 0; i < int_var.size(); i++) {
            int rem = target_value - int_var[i];
            if(tv.count(rem) > 0) {
                out = Output(tv[rem], i);
                return out;
            }
            else {

                tv[int_var[i]] = i;
            }
        }
    }
    return  out;

}

Output two_sum(vector<int> int_var, int target_value)
{
    Output out = Output(0, 0);
    

    if(int_var.empty()) {
        out = Output(0, 0);
        return out;
    }
    else if(int_var.size() == 1) {
        out = Output(0, 0);
        return out;
    }
    else if(int_var.size() == 2) {
        auto sum = int_var[0] + int_var[1];
        if(sum == target_value) {
            out = Output(0, 1);
        }
        else {
            out = Output(0, 0);
        }
        return out;
    }
    else {
        for(int i = 0; i < int_var.size(); ++i) {
            int rem = target_value - int_var[i];
            for(int j = i + 1; j < int_var.size(); ++j) {
                if(rem == int_var[j]) {
                    // cout << int_var[i]  << " " << int_var[j] << endl;
                    out = Output(i, j);
                    return out;
                }
            }

        }

    }

   return out; 

}


int main()
{
    vector<int> array {2, 7, 3, -1, 4};
    vector<int> array_1 {2, 7, 3, -1, 4};
    vector<int> array_2 {2, 7};
    vector<int> array_3 {25};
    vector<int> array_4 {};

    vector<TestCase> test_cases {TestCase(Input(array), Output(2, 3), 2),
                                 TestCase(Input(array_1), Output(0, 0), 100),
                                 TestCase(Input(array_2), Output(0, 1), 9),
                                 TestCase(Input(array_3), Output(0, 0), 25),
                                 TestCase(Input(array_4), Output(0, 0), 10)};


    // TestCase tc1;
    // Output out1;
    // out1.first = 8;
    // out1.second = 9;

    // tc1.input = vector<int>{2, 4, 8, 4, 4, 9};
    // tc1.output = out1;
    // test_cases.push_back(tc1);


    for (TestCase tc: test_cases) {
        
        Output actual_output = two_sum_mtwo(tc.input.get(), tc.target_value);
        if (actual_output != tc.output) {
            
            cout << "For input ";
            cout << tc.input;
            cout << "and target value ";
            cout << tc.target_value;
            cout << ", expected " << tc.output;
            cout << ", got " << actual_output;
            cout << endl;
        }
        
    }
    return 0;
    
}