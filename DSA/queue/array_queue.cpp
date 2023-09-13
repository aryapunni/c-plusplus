#include <cctype>
#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Queue {
    private:
        vector<string> names;
        int front = 0;
        int rear = -1;
        int size = 0;

    public:

        Queue() {
            names = {};
            front = 0;
            rear = -1;
            size = 0;
        }

        void enqueue(string name) {
            names.push_back(name);
            rear++;
            size++;

        }

        string dequeue() {

            if(size == 0) {
                return "";
            }
            string value = names[front]; 
            front++;
            size--;
            return value;

        }

        int length() {
            return size;
        }

        string peek_front() {
            if(size == 0) {
                return "";
            }

            return names[front];
            
        }

        string peek_rear() {
            if(size == 0) {
                return "";
            }

            return names[rear];
        }

        void print() {

            if(size == 0) {
                cout << "Queue is empty" << endl;
                return;
            }

            vector<string>::iterator itr;

            for(itr = names.begin(); itr < names.end(); itr++) {

                cout << *itr << endl;

            }

        }
};

int main(void) {
    Queue queue1 = Queue();
    queue1.enqueue("Arya");
    queue1.enqueue("Jyothis");
    queue1.enqueue("Midhun");
    queue1.enqueue("Alekhya");
    queue1.enqueue("Bindu");
    queue1.enqueue("Velunni");

    queue1.print();

    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;
    cout << queue1.dequeue() << "\tsize: " << queue1.length() << "\trear: " << queue1.peek_rear() << "\tfront: " << queue1.peek_front() << endl;


    return 0;
}