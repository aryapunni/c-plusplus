//Leet code question 509: Fibonacci - In the Fibonacci sequence, each subsequent term is obtained by adding the preceding 2 terms. 
//This is true for all the numbers except the first 2 numbers of the Fibonacci series as they do not have 2 preceding numbers. 
//The first 2 terms in the Fibonacci series is 0 and 1. F(n) = F(n-1)+F(n-2) for n>1. 
//Write a function that finds F(n) given n where n is an integer greater than equal to 0. 
//For the first term n = 0. 

#include <iostream>
#include <vector>
#include <map>
using namespace std;

std::map<int, int> fibMap;

void print_map(map<char, char> test) {
    map<char, char>::iterator itr; 
    for(itr = test.begin(); itr != test.end(); ++itr) {
        cout << "\t" << itr->first << "\t" << itr->second <<"\n";
    }
    cout << endl;
}

// Fibonacci series with memoization
int fibonacciMemo(int n) {

    fibMap[0] = 0;
    fibMap[1] = 1;

    if(fibMap.find(n) == fibMap.end()) {

        fibMap[n] = fibonacciMemo(n-1) + fibonacciMemo(n-2);
        return fibMap[n];
    }
    else {
        return fibMap[n];
    }

}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


int fibonacci_brute(int n) {

    int current = 1;
    int prev = 0;
    int result = 0;
    if(n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
       for(int i = 1; i < n; i++) {

        result = current + prev;
        prev = current;
        current = result;

        
       }

    }
    return  result;

}


class TestCase {
    public:
        int input;
        int output;
    TestCase(int in, int out) {
        input = in;
        output = out;
    }

};


int main(void) {

    int input = 0;
    int input_1 = 1;
    int input_2 = 2;
    int input_3 = 3;
    int input_4 = 4;
    int input_5 = 5;
    int input_6 = 6;
    int input_7 = 7;

    vector<TestCase> test_cases = {TestCase(input, 0), 
                                    TestCase(input_1, 1), 
                                    TestCase(input_2, 1), 
                                    TestCase(input_3, 2), 
                                    TestCase(input_4, 3),
                                    TestCase(input_5, 5),
                                    TestCase(input_6, 8), 
                                    TestCase(input_7, 13)};
    

    for(TestCase tc : test_cases) {
        int result = fibonacciMemo(tc.input);
        if(result != tc.output) {
            cout << "For input ";
            cout << tc.input << "\t";
            cout << ", expected " << tc.output;
            cout << ", got " << result;
            cout << endl;
        }
    }
                                    

    return 0;
}