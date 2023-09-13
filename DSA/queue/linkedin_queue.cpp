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
        string name;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(string input) {
            name = input;
            next = nullptr;
            prev = nullptr;
        }
};


class Queue {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int size = 0;

    public:
        Queue() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void enqueue(string name) {

            Node *newnode = new Node(name);

            if(head == nullptr) {
                tail = newnode;
                head = newnode;
                size++;
                return;
            }

            Node *temp = tail;
            newnode->prev = temp;
            temp->next = newnode;
            tail = newnode;
            size++;

        }

        string dequeue() {

            if(head == nullptr) {
                return "";
            }

            string name = head->name;
            Node *temp = head;
            if(temp->next == nullptr) {

                head = nullptr;
                tail = nullptr;
                delete temp;
                size--;
                return name;


            }
            temp->next->prev = nullptr;
            head = head->next;
            delete temp;
            size--;
            return name;
        }

        void print() {
            if(head == nullptr) {
                cout << "Queue seems to be empty" << endl;
                return;
            }

            Node *temp = head;

            while(temp != nullptr) {
                cout << temp->name << endl;
                temp = temp->next;
            }
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
    
};

int main(void) {

    Queue queue1 = Queue();

    queue1.enqueue("Arya");
    queue1.enqueue("Jyothis");
    queue1.enqueue("Midhun");
    queue1.enqueue("Alekhya");
    queue1.enqueue("Velunni");
    queue1.enqueue("Bindu");
    queue1.enqueue("Navaneeth");
    queue1.enqueue("Raji");

    queue1.print();

    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    queue1.enqueue("Liji");
    cout << "size: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    queue1.enqueue("Suja");
    cout << "size: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;
    queue1.enqueue("Amina");
    cout << "size: " << queue1.length() << "\tis empty: " << queue1.is_empty() << endl;


    queue1.print();
    return 0;
}

