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


class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node() {
            data = 0;
            left = nullptr;
            right= nullptr;
        }

        Node(int input) {
            data = input;
            left = nullptr;
            right = nullptr;
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

        void enqueue(Node *adr) {
            q.push_back(adr);
            rear++;
            size++;
        }

        Node *dequeue() {
            if(size == 0) {
                return nullptr;
            }
            Node *adr = q[front];
            front++;
            size--;
            return adr;

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



void inorder_print(Node * parent) {
    if(parent == nullptr) {
        return;
    }

    inorder_print(parent->left);
    cout << parent->data << ", ";
    inorder_print(parent->right);
}


Node *mirror(Node* parent) {
    if(parent == nullptr) {
        return nullptr;
    }

    Queue q = Queue();
    q.enqueue(parent);

    while (!q.is_empty()) {
        Node *temp = q.dequeue();

        Node *left = temp->left;
        temp->left = temp->right;
        temp->right = left;

        if(temp->left) {
            q.enqueue(temp->left);
        }

        if(temp->right) {
            q.enqueue(temp->right);
        }

    
    }


    return parent;
}

Node *mirror_recursion(Node *parent) {

    if(parent == nullptr) {
        return nullptr;
    }

    Node *temp = parent->left;
    parent->left = parent->right;
    parent->right = temp;

    if(parent->left) {
        mirror_recursion(parent->left);
    }

    if(parent->right) {
        mirror_recursion(parent->right);
    }

    return parent;

}


int main(void) {

    Node *root = new Node(21);

    insert(root, 10);
    insert(root, 42);
    insert(root, 9);
    insert(root, 15);
    insert(root, 36);
    insert(root, 53);
    insert(root, 48);
    insert(root, 82);

    inorder_print(root);
    cout << endl;

    // mirror_recursion(root);
 
    // inorder_print(root);
    // cout << endl;

    mirror(root);
 
    inorder_print(root);
    cout << endl;

  

    return 0;
}
