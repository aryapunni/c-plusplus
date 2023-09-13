#include <cctype>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <system_error>
#include <vector>
#include <map>

using namespace std;

class Node {
    public:
        int number;
        Node *left;
        Node *right;

        Node() {
            left = nullptr;
            right = nullptr;
        }

        Node(int input) {
            number = input;
            left = nullptr;
            right = nullptr;
        }
};

class Queue{

    private:
        vector<Node *> input;
        int front;
        int rear;
        int size;

    public:

        Queue() {
            input = {};
            front = 0;
            rear = -1;
            size = 0;
        }

        void enqueue(Node* address) {

            input.push_back(address);
            rear++;
            size++;

        }

        Node* dequeue() {

            if(size == 0) {
                return 0;
            }
            Node *number = input[front];
            front++;
            size--;
            return number;
        }

        bool is_empty() {
            if(size == 0) {
                return true;
            }
            else {
                return false;
            }
        }

        void print() {
            int i;
            int end = rear;

            for(i = front; i <= rear; i++) {
                cout << input[i] << "\t";
            }

            cout << endl;
        }

};

Node *insert(Node *parent, int input) {

    
    if(parent == nullptr) {
        Node *newnode = new Node(input);
        return newnode;
    }

    if(input < parent->number) {
        parent->left = insert(parent->left, input);
    }
    else if(input > parent->number) {
        parent->right = insert(parent->right, input);
    }

    return parent;

}

void inorder_print(Node *parent) {

    if(parent == nullptr) {
        return;
    }

    inorder_print(parent->left);

    cout << parent->number << ", ";
    inorder_print(parent->right);


}

int search(Node *parent, int input) {
    int number = 0;

    if(parent == nullptr) {
        cout << "No such number in this tree" << endl;
        return -1;
    }

    if(input == parent->number) {
        number = parent->number;
    }
    else if(input < parent->number) {
        search(parent->left, input);
    }
    else {
        search(parent->right, input);
    }

    return number;
}

void listprint(vector<int> input) {
    cout << "{";
    if(input.empty()) {
        cout << "}";
        return;
    }
    vector<int>::iterator ptr;
    for(ptr = input.begin(); ptr < input.end(); ptr++) {
        cout << *ptr << ", ";

    }
    cout << "}" << endl;
}

void breadthfirsttravel(Node *parent) {

    Queue line = Queue();
    vector<int> list;

    line.enqueue(parent);

    line.print();

    while(!(line.is_empty())) {

        Node *node_addr = line.dequeue();

        list.push_back(node_addr->number);

        if(node_addr->left != nullptr) {
            line.enqueue(node_addr->left);

        }

        if(node_addr->right != nullptr) {
            line.enqueue(node_addr->right);

        }
        listprint(list);
        line.print();

    }


}


int main(void) {

    Node *bst = new Node(20);

    bst = insert(bst, 40);
    bst = insert(bst, 10);
    bst = insert(bst, 13);
    bst = insert(bst, 43);
    bst = insert(bst, 8);
    bst = insert(bst, 11);
    bst = insert(bst, 41);

    inorder_print(bst);
    cout << endl;
    breadthfirsttravel(bst);

    Queue newq = Queue();

    return 0;
} 
    // newq.enqueue(3);
    // newq.enqueue(1);
    // newq.enqueue(4);
    // newq.enqueue(1);
    // newq.enqueue(5);
    // newq.enqueue(9);
    // newq.enqueue(2);

    // newq.print();

    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // cout << newq.dequeue() << "\t" << newq.is_empty() << endl;
    // newq.enqueue(3);
    // newq.enqueue(3);
    // newq.enqueue(3);
    // newq.print();



