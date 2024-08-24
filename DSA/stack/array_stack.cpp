#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;



class Namestack {

    public:
        vector<string> name_list;
        int size = 0;
        int top = -1;

        Namestack() {
            name_list = {};
            size = 0;
            top = -1;
        }

        void push(string name) {
            top++;
            name_list.push_back(name);
            size++;
        }

        string pop() {
            if(size == 0) {
                cout << "stack is empty" << endl;
                return "";
            }

            string name = name_list[top];
            top--;
            size--;
            return name;
        }

        string top_val() {
            if(size == 0) {
                cout << "Stack seems to be empty" << endl;
                return "";
            }
            return name_list[top];
        }

        bool is_empty() {
            if(size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        int size_val() {
            return size;
        }


};


int main(void) {

    Namestack stack1 = Namestack();

    string val = stack1.top_val();

    stack1.push("Arya");
    stack1.push("Jyothis");
    stack1.push("Midhun");
    stack1.push("Alekhya");
    stack1.push("Bindu");
    stack1.push("Velunni");

    cout << stack1.top_val() << endl;

    cout << stack1.is_empty() << endl;
    cout << stack1.pop() << endl;
    cout << stack1.top_val() << endl;

    return 0;
}

