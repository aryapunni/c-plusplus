//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string ""

#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    string prefix = strs[0];
    int length = strs[0].size();

    if(strs.size() == 1) {
        return prefix;
    }
    int j = 0;

    for(int i = 1; i < strs.size(); i++) {
        j = 0;

        while(j < strs[i].size()) {
            if(strs[i][j] == prefix[j]) {
                j++;
            }
            else {
                break;
            }
            
        }
        
        if(j < length) {
            length = j;
        }


    }

    prefix = prefix.substr(0, length);


    return prefix;
}

int main(void) {

    vector<string> strs = {"dog","racecar","car"};
    string output = longestCommonPrefix(strs);

    cout << output << endl;

    return 0;

}
