#include <cstddef>
#include<iostream>
#include<string>
#include<map>
#include <utility>

using namespace std;


//simple map solution
int nonRepeatMap(string input) {

    map<char, int> charMap;

    for(int i = 0; i < input.length(); i++) {

        if(charMap.find(input[i]) == charMap.end()) {

            charMap[input[i]] = 1;

        }
        else {
            ++charMap[input[i]];
        }
    }

    for(int j = 0; j < input.length(); j++) {

        if(charMap[input[j]] == 1) {
            return j;
        }
    }

    return -1;

}



//too complex map solution
int nonRepeatchar(string input) {

    map<char, int> charMap;
    map<int, int> indexMap; 
    int index = input.length();
    

    cout << "length\t" << index << endl;

    for(int i = 0; i < input.length(); i++) {
        

        if(charMap.find(input[i]) == charMap.end()) {

            charMap[input[i]] = i;
            indexMap[i] = 1;

        }
        else {
            ++indexMap[charMap[input[i]]];
        }

    }

    for(auto& t : charMap) {
        cout << t.first << "\t" << t.second << endl;
    }

    cout << "index map is: \n";

    for(auto& t : indexMap) {

        
        if(t.second < 2) {
            cout << t.first << "\t" << t.second << endl;

            if(t.first < index) {
                index = t.first;
            }

        }

    }

    cout << "index is: \t" << index << endl;

    if(0 <= index) {
        if(index > (input.length() - 1)) {
            return -1;
        }

    }

   return index;

}

//iterative solution
int nonRepeat(string input) {


    for(int i = 0; i < input.length(); i++) {

        int count = 0;

        for(int j = 0; j < input.length(); j++) {

            if(input[j] == input[i]) {

                count++;

            }

        }


        cout << "input[i]\t" << input[i] << "\tcount\t" << count << endl;

        if(count == 1) {
            return i;
        }
    }

    return -1;
}


int main(void) {

    string s = "aAA1ac";
    int output = nonRepeatMap(s);
    cout << "\n-------------------------------------";
    cout << endl << output << endl;
    return 0;
}