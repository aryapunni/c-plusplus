#include <cctype>
#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Node{
    public:
        string name;
        Node *next = nullptr;

        Node(string input) {
            name = input;
            next = nullptr;
        }

};

class Stack{
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
                size++;
                top++;
                return;
            }

            Node *temp = head;
            newnode->next = temp;
            head = newnode;
            size++;
            top++;

        }

        string pop() {
            if(head == nullptr) {
                return "";
            }

            string name = head->name;

            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            top--;
            return name;
        }

        string top_view() {
            if(head == nullptr) {
                return "";
            }

            return head->name;
        }

        bool is_empty() {
            if(size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        int length() {
            return size;
        }

        void print() {

            Node *temp = head;
            while(temp != nullptr) {
                cout << temp->name << endl;
                temp = temp->next;
            }
        }
};


class Queue{

    private:
        Stack *first = nullptr;
        Stack *second = nullptr;
        int size = 0;

    public:
        Queue() {
            first = new Stack();
            second = new Stack();
            size = 0;
        }

        void enqueue(string name) {

            first->push(name);
            size++;

        }

        string dequeue() {

            string name;
            // cout << "here" << endl;

            if(second->is_empty()) {

                while(first->length() != 0) {
                    name = first->pop();
                    second->push(name);
                }

                name  = second->pop();
                size--;

            }
            else {
                name = second->pop();
                size--;
            }

           return name;

        }

        void print() {
            first->print();
        }

        bool is_empty() {
            if(second->is_empty() && first->is_empty()) {
                return true;
            }
            else {
                return false;
            }
        }


        string peek_front() {

            string name;

            if(second->is_empty()) {
                while (first->length() != 0) {

                    name = first->pop();
                    second->push(name);
                
                }
                name = second->top_view();
            }
            else {
                name  = second->top_view();
            
            }

            return name;


        }


};



int main(void) {

    Queue q1 = Queue();

    q1.enqueue("Arya");
    q1.enqueue("Jyothis");
    q1.enqueue("Alekhya");
    q1.enqueue("Midhun");
    q1.enqueue("Bindu");
    q1.enqueue("Velunni");

    q1.print();

    cout << q1.dequeue() << endl;
    cout << q1.peek_front() << endl;
    cout << q1.peek_front() << endl;
    cout << q1.peek_front() << endl;
    cout << q1.peek_front() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;
    cout << q1.dequeue() << "\t" << q1.is_empty() << endl;

    // cout << stk.pop() << "\ttop view: " << stk.top_view() << "\tlength: " << stk.length() << "\tis empty: " << stk.is_empty() << endl;  
    // stk.print();
    return 0;
}
