#include<iostream>
#include<string>
using namespace std;


bool isPalindromeBrute(string input) {

    
    int length = input.length();
    char copy[length];
    int end = length - 1;
    int j = 0;

    for(int i = end; i >= 0; i--) {
        
        copy[j] = input[i];
        j++;
    }

    int size = sizeof(copy)/sizeof(char);

    copy[length] = '\0';


    if(copy == input) {
        cout << endl << "Is palindrome" << endl;
        return true;
    }

    cout << "reverse copy string: \t" << copy <<  endl;
    return false;
}


bool isPalindrome(string input) {

    int length = input.length();
    int end = length - 1;

    if(length == 1) {
        return true;
    }
    else if (length == 2) {

        if(input[0] != input[1]) {
            return false;
        }
        else {
            return  true;
        }
    
    }
    else {
       for(int i = 0, j = end; i != j && i < j; i++, j--) {

            cout << "input[i]\t" << input[i] << "\tinput[j]\t" << input[j] << endl;
            if(input[i] != input[j]) {
                return false;
            }
        }
    
    }

    return true;
}


int main(void) {

    string s = "aA";
    bool result;

    result = isPalindromeBrute(s);
    cout << "------------------------------" << endl;
    cout << "result: \t" << result;
    cout << endl;
    return 0;
}