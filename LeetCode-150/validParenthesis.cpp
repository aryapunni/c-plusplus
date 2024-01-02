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
        char s;
        Node *next = nullptr;

        Node(char input) {
            s = input;
            next = nullptr;
        }
};

class stack {
    private:
        Node *head = nullptr;
        int size = 0;
        int top = -1;

    public:

        stack() {
            // Node *newnode = new Node(input);
            head = nullptr;
            size = 0;
            top = -1;
        }

        void push(char s) {

            Node *newnode = new Node(s);

            if(head == nullptr) {
                head = newnode;
                size++;
                top++;
                return;
            } 

            Node *temp = head;
            head->next = newnode;
            head = newnode;
            top++;
            size++;

        }

        char pop() {
            char val = head->s;
            Node *temp = head;
            

            return val;
        }


};

bool isValid(string s) {

    return true;

}



int main(void) {
    return 0;
}