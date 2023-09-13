#include <cctype>
#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
    public:
        string numeral;
        Node *next = nullptr;

        Node(string input) {
            numeral = input;
            next = nullptr;
        }
};


class Stack {
    private: 

        Node *head = nullptr;
        int top = -1;
        int size = 0;

    public:

        Stack() {
            head = nullptr;
            top = -1;
            size = 0;
        }

        void print() {
            Node *temp = head;

            while(temp != nullptr) {
                cout << temp->numeral << endl;
                temp = temp->next;
            }
        }

        void push(string numeral) {
            Node *newnode = new Node(numeral);

            if(head == nullptr) {
                head = newnode;
                top++;
                size++;
                return;
            } 

            Node *temp = head;
            newnode->next = temp;
            head = newnode;
            top++;
            size++;
        }


        string pop() {
            
            if(head == nullptr) {
                return "";
            }

            string numeral = head->numeral;

            Node *temp = head;
            head = head->next;
            delete temp;
            top--;
            size--;
            return numeral;
        }

        bool is_empty() {
            if(size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        string top_view() {
            if(head == nullptr) {
                return "";
            }
            return head->numeral;
        }


        int length() {
            return size;
        }

        bool is_number(string input) {
            // if a number return true

            if(input == "") {
                return false;
            }

            string::const_iterator itr = input.begin();

            //iter throgh string if each char is a digit
            //if char is not a digit exit loop
            while((itr != input.end()) && (isdigit(*itr))) {
                itr++;
            }

            //if itr is at the end of the string 
            //the whole string was a number 
            //else it was not
            if(itr == input.end()) {
                return true;
            }
            else {
                return false;
            }
        }

        int calculate(string sign, string input_1, string input_2) {


            int in1 = 0;
            int in2 = 0;

            if(is_number(input_1) && is_number(input_2)) {

                cout << "assigning in1 and in2" << endl;

                in1 = stoi(input_1);
                in2 = stoi(input_2);
            }

            
            
            if(sign == "+") {

                return in1 + in2;

            }
            else if(sign == "-") {

                return in2 - in1;

            }
            else if(sign == "/") {

                return in2/in1;

            }
            else if(sign == "*") {

                return in1 * in2;

            }
            else {

                return 0;

            }



        }

        void sum(vector<string> input) {

            vector<string>::iterator itr;

            for(itr = input.begin(); itr != input.end(); itr++) {
                // push current array value to stack
                push(*itr);

                // view the current top value 
                string current_value = top_view();

                if(current_value == "") {
                    return;
                }

                // if current value is a number
                // do nothing
                // else follow this routine
                if(!is_number(current_value)) {         //if not a number
                    string sign = pop();
                    string input_1 = pop();
                    string input_2 = pop();

                    int result = calculate(sign, input_1, input_2);

                    cout << result << endl;

                    push(to_string(result));


                }
                else {
                    cout << "is a number" << endl;
                }




            }
        }


};


int main(void) {

    Stack numerals = Stack();

    numerals.push("1");
    numerals.push("2");
    numerals.push("3");
    numerals.push("4");
    numerals.push("5");
    numerals.push("+");

    // numerals.print();

    // cout << numerals.length() << endl;
    // cout << numerals.pop() << "\t" << numerals.is_empty() << endl;
    // cout << numerals.pop() << "\t" << numerals.length() << endl;

    vector<string> input {"10", "6", "9", "3", "+", "11", "*", "/", "*", "17", "+", "5", "+"};

    Stack stack_1 = Stack();
    stack_1.sum(input);


    return 0;
}
