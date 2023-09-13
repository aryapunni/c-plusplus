#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Input {
    public: 
        string s;
        string t;

    public:
        Input() {}

        Input(string str1, string str2) {
            s = str1;
            t = str2;
        }
};

class TestCase {
    public:
        Input input;
        bool result;

    TestCase(Input in, bool r) {
        input = in;
        result = r;
    }
};


void print_map(map<char, char> test) {
    map<char, char>::iterator itr; 
    for(itr = test.begin(); itr != test.end(); ++itr) {
        cout << "\t" << itr->first << "\t" << itr->second <<"\n";
    }
    cout << endl;
}



bool isomorphic(Input input) {

    std::map<char, char> key_map;
    std::map<char, char> val_map;

    if(input.s.length() != input.t.length()) {
        return false;
    }
    else {
        for(int i = 0; i < input.s.length(); i++) {


            if(key_map.find(input.s[i]) == key_map.end()) {

                if(val_map.find(input.t[i]) == val_map.end()) {

                    key_map[input.s[i]] = input.t[i];

                    val_map[input.t[i]] = input.s[i];
                }
                else {

                    return false;
                }


            } 
            else {

                if(val_map.find(input.t[i]) == val_map.end()) {
                    return false;
                }

            }

            
        }
        // print_map(key_map);
        // print_map(val_map);

        
    }
    return true;
}



int main(void) {

    Input input_1 = Input("ababr", "eoeoo");
    Input input_2 = Input("ababr", "pqrqo");
    Input input_3 = Input("green", "abccd");
    Input input_4 = Input("egg", "add");
    Input input_5 = Input("foo", "bar");
    Input input_6 = Input("paper", "title");

    vector<TestCase> test_cases {TestCase(input_1, false),
                                TestCase(input_2, false),
                                TestCase(input_3, true),
                                TestCase(input_4, true),
                                TestCase(input_5, false),
                                TestCase(input_6, true)};


    for(TestCase tc: test_cases) {
        bool output = isomorphic(tc.input);
        if(output != tc.result) {
            cout << "For input ";
            cout << tc.input.s << "\t" << tc.input.t;
            cout << ", expected " << tc.result;
            cout << ", got " << output;
            cout << endl;
        }

    }

        

    return 0;
}
