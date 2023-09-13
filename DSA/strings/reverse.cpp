#include<iostream>
#include<string>
using namespace std;

string reverse(string input) {

    string copy = input;
    char temp;
    int length = input.length();
    int end = length - 1;
    cout << "copy: \t" << copy << endl;

    for(int i = 0, j = end; i != j && i < j; i++, j--) {

        cout << copy[i] << "\t" << copy[j] << endl;

        temp = copy[i];
        copy[i] = copy[j];
        copy[j] = temp;

    }

    return copy;
}

int main(void) {

    string s = "jyothis";

    string result = reverse(s);
    cout << "-------------------------------" << endl;
    cout << "result: \t" << result;
    cout << endl;
    return 0;
}

