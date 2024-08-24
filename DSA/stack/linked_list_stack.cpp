#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Node {
    public:
        string name;
        Node *next = nullptr;

        Node(string input) {

            name = input;
            next = nullptr;

        }

};

class Stack {
    private:

        Node *head = nullptr;
        int size = 0;
        int top = -1;

    public:

        Stack() {
            head = nullptr;
            size = 0;
            top = -1;
        }

        void push(string name) {
            Node *newnode = new Node(name);

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

        void print() {

            Node *temp = head;

            while(temp != nullptr) {
                cout << temp->name << endl;
                temp = temp->next;
            }


        }

        string pop() {
            if(head == nullptr) {
                cout << "stack seems to be empty" << endl;
                return "";
            }

            string name = head->name;
            top--;
            size--;
            Node *temp = head;
            head = head->next;
            delete temp;
            return name;
        }

        string top_view() {
            if(head == nullptr) {
                cout << "stack seems to be empty" << endl;
                return "";
            }

            return head->name;
        }

        int length() {

            return size;

        }

        bool is_empty() {
            if(size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

};


int main(void) {

    Stack stack_1 = Stack();

    stack_1.push("Arya");
    stack_1.push("Jyothis");
    stack_1.push("Midhun");
    stack_1.push("Alekhya");
    stack_1.push("Bindu");
    stack_1.push("Velunni");

    // stack_1.print();

    cout << stack_1.pop() << endl;
    // stack_1.print();
    cout << stack_1.top_view() << endl;
    cout << stack_1.is_empty() << endl;
    cout << stack_1.length() << endl;


    return 0;
}

