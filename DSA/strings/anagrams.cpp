#include<iostream>
#include<map>
#include <shared_mutex>
#include<vector>
#include<string>

using namespace std;

void print_vector(vector<string> input) {
    if(input.empty()) {
        cout << "{}";
    }
    else {
        cout << "{\t";
        for(int i = 0; i < input.size(); i++) {
             cout << input[i] << "\t";
        }
        cout << "}\n";
    }
}


void print_map(map<char, int> test) {

    map<char, int>::iterator itr; 
    for(itr = test.begin(); itr != test.end(); ++itr) {
        cout << "\t" << itr->first << "\t" << itr->second <<"\n";
    }
    cout << endl;
}

void printNestedStrVector(vector<vector<string>> input) {

    for(int i = 0; i < input.size(); i++) {

        for(int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << "\t";
        }
        cout << endl;
    }
}

string sortString(string input) {

    int length = input.length();
    int end = length - 1;
    bool swapped = false;


    for(int i = 0; i < end; i++) {

        for(int j = 0; j < end - i; j++) {

            if(input[j] > input[j + 1]) {
                swap(input[j], input[j + 1]);
                swapped = true;
            }

        }

        if(swapped == false) {
            break;
        }

    }

    return input;
}

vector<vector<string>> findAnagramseff(vector<string> input) {

    vector<string> charSortedStrings;
    map<string, vector<string>> anagrams;
    vector<vector<string>> result;

    for(int i = 0; i < input.size(); i++) {

        charSortedStrings.push_back(sortString(input[i]));

    }

    print_vector(input);
    print_vector(charSortedStrings);

    for(int j = 0; j < input.size(); j++) {
        if(anagrams.find(charSortedStrings[j]) == anagrams.end()) {
            anagrams[charSortedStrings[j]] = {input[j]};
        }
        else {
            anagrams[charSortedStrings[j]].push_back(input[j]);
        }

    }

    for(auto itr = anagrams.begin(); itr != anagrams.end(); itr++) {
        result.push_back(itr->second);
    }

    printNestedStrVector(result);



    return result;

}


vector<vector<string>> findAnagrams(vector<string> input) {


    map<char, int> charMap;
    vector<string> anagrams;

    for(string inputItem : input) {

        inputItem = *input.begin();
        cout << "First item from the input list: \t" << inputItem << endl;

        int char_loc = 0;

        for(char c : inputItem) {
            charMap[c] = char_loc;
            char_loc++;
        }
        for(auto itr = input.begin(); itr != input.end(); itr++) {
            
            string word = *itr;

            int count = 0;
            cout << *itr << endl;
            for(char c : *itr) {
                if(charMap.find(c) != charMap.end()) {
                    cout << c << "\t";
                    count++;
                }
                else {
                    cout << "\nNot in charmap\t" << c ;
                    
                    break;
                }
                cout << "count: \t" << count << endl;
                if(count == word.length()) {
                    anagrams.push_back(*itr);
                    input.erase(itr);
                    --itr;

                }

            }
            cout << endl;

        }
        print_map(charMap);
        charMap.clear();
        cout << "anagrams: \t" <<endl;
        print_vector(anagrams);
        cout << "original vector: \t" << endl;;
        print_vector(input);
        cout << "input length: \t" << input.size();

        cout << endl;
        cout << endl;



        if(input.size() == 0) {
            break;
        }

    }


    return {{"eat", "tea", "aet"}, {"tan", "nat"}, {"bat"}};
}

int main(void) {

    vector<string> input = {"eat", "tea", "tan", "aet", "nat", "bat"};

    vector<vector<string>> result = findAnagramseff(input);

    return 0;
}