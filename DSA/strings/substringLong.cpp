#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
using namespace std;


void print_map(map<char, int> test) {
    map<char, int>::iterator itr; 
    for(itr = test.begin(); itr != test.end(); ++itr) {
        cout << "\t" << itr->first << "\t" << itr->second <<"\n";
    }
    cout << endl;
}

int longSubstringEff(string input) {

    map<char, int> charMap;
    int start = 0;
    int lenCount = 0;
    int maxLength = 0;

    for(int i = 0; i < input.length(); i++) {
        cout << i << "\tinput[i]\t" << input[i] << endl;
        if(charMap.find(input[i]) == charMap.end()) {
            cout << "**New character**" << endl;
            charMap[input[i]] = i;
            lenCount++;
            if(maxLength < lenCount) {
                maxLength = lenCount;
            }
            cout << "lencount: \t" << lenCount << endl;
            cout << "maxLength: \t" << maxLength << endl;
            cout << "start: \t" << start << endl;
        }
        else {

            cout << "**Existing character**" << endl;
            cout << start << "\t" << charMap[input[i]] << endl;
            start = max(start, charMap[input[i]] + 1);
            cout << start << endl;

            lenCount = (i - start) + 1;
            charMap[input[i]] = i;
            cout << "lencount: \t" << lenCount << endl;
            cout << "maxLength: \t" << maxLength << endl;
            cout << "start: \t" << start << endl;
 
        }

        cout << endl;
        cout << endl;
    }

    print_map(charMap);
    return maxLength;
}


int longSubstring(string input) {

    map<string, int> substringMap;
    int length = input.length();
    string substring;
    int substringLength = 0;
    substring.append(input, 0, 1);

    for(int i = 1; i < length; i++) {

        int status = 0;
        cout << "input[i]==> \t" << input[i] << "\t" << endl;
        cout << "substring==>\t" << substring << endl;

        for(int j = 0; j < substring.length(); j++) {

            cout << "substring[j]: \t"<< j << "\t" << substring[j] << endl;


            if(input[i] != substring[j]) {
                status++;
            }
            else {
                
                //substringMap[substring] = substring.length();
                if(substringLength < substring.length()) {
                    substringLength = substring.length();
                }
                substring = substring.substr(j + 1);
                cout << "removing......\t" << substring << endl;
                j--;
                //status = 0;
            }

        }

        cout << "status\t" << status << "\n";
        if((status == substring.length()) || (substring.length() == 0)) {
            substring.append(input, i , 1);
            //substringMap[substring] = substring.length();
            if(substringLength < substring.length()) {
                substringLength = substring.length();
            }
            cout << "appending...\t" << substring << endl;
        }
        
        cout << endl;
        cout << endl;

    }

    // print_map(substringMap);
    cout << endl;

    return substringLength;
} 


int main(void) {

    string s = "abcdabefqa";
    int result = longSubstringEff(s);
    cout << "\n" << "----------------------------------" << endl;
    cout << "result: \t" << result << endl;
    return 0;
}