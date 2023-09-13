#include <cctype>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include<iostream>
#include <iterator>
#include <memory>
#include <string>
#include <system_error>
#include <type_traits>
#include <vector>
#include <map>


using namespace std;



class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node() {
            data = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(int input) {
            data = input;
            left = nullptr;
            right = nullptr;
        }
};


class Stack{
    private:
        vector<Node *> stck;
        int size;
        int end;

    public:

        Stack() {
            stck = {};
            size = 0;
            end = -1;
        }

        void push(Node *address) {
            stck.push_back(address);
            size++;
            end++;
        }

        Node *pop() {

            if(size == 0) {
                return nullptr;
            }
            Node *result = stck[end];
            stck.pop_back();
            end--;
            size--;
            return result;

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
            for(int i = 0; i < size; i++) {
                cout << stck[i] << ", ";
            }

            cout << endl;
        }
};

class Queue{

    private:
        vector<Node *> q;
        int size = 0;
        int front = 0;
        int rear = -1;

    public:

        Queue() {
            q = {};
            size = 0;
            front = 0;
            rear = -1;
        }

        void enqueue(Node *address) {
            q.push_back(address);
            size++;
            rear++;
        }

        Node* dequeue() {
            if(size == 0) {
                return nullptr;
            }
            Node *result = q[front];
            front++;
            size--;
            return result;
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
            for(int i = front; i <= rear; i++) {
                cout << q[i] << ", ";
            }

            cout << endl;
        }

};


void inorder_print(Node * parent) {
    if(parent == nullptr) {
        return;
    }

    inorder_print(parent->left);
    cout << parent->data << ", ";
    inorder_print(parent->right);
}



Node *insert(Node *parent, int input) {

    if(parent == nullptr) {

        return new Node(input);

    }

    if(input < parent->data) {

        parent->left = insert(parent->left, input);

    }
    else if (input > parent->data) {

        parent->right = insert(parent->right, input);
    
    }

    return parent;

}


void leftSideview(Node *parent) {

    Queue q = Queue();
    vector<int> leftview;
    Node *temp;

    q.enqueue(parent);

    while(!q.is_empty()) {

        int size = q.length();
        int count = 0;

        while(count < size) {


            temp = q.dequeue();
            if(temp->left != nullptr) {

                q.enqueue(temp->left);

            }
            if(temp->right != nullptr) {

                q.enqueue(temp->right);

            }
            count++;

        }

        cout << temp->data << endl;
        leftview.push_back(temp->data);
        
    }
}


void rightSideview(Node* parent) {

    Queue q = Queue();
    vector<int> rightview;
    Node *temp;

    q.enqueue(parent);

    while(!q.is_empty()) {

        int size = q.length();
        int count = 0;

        while(count < size) {


            temp = q.dequeue();
            if(count == 0) {
                cout << temp->data << endl;
                rightview.push_back(temp->data);

            }
            if(temp->left != nullptr) {

                q.enqueue(temp->left);

            }
            if(temp->right != nullptr) {

                q.enqueue(temp->right);

            }
            count++;

        }

        
    }

}





int main(void) {

    Node *root = new Node(4);

    insert(root, 1);
    insert(root, 3);
    insert(root, 2);
    insert(root, 8);
    insert(root, 7);
    insert(root, 5);
    insert(root, 12);

    // inorder_print(root);
    cout << endl;

    leftSideview(root);
    rightSideview(root);
    return 0;
}