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
        int number;
        Node *left;
        Node *right;

        Node() {
            // number = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(int input) {
            number = input;
            left = nullptr;
            right = nullptr;
        }



};
int search(Node *parent, int input) {

    Node *temp = parent;
    int number;

    if(temp == nullptr) {
        cout << "There is no such value" << endl;
        return -1;
    }

    cout << "Number: " << temp->number << endl;
    if (input > temp->number) {
        number = search(temp->right, input);
    
    }
    else if (input < temp->number) {

        number = search(temp->left, input);
    
    }
    else {
        cout << "EQUAL-Number: " << temp->number << endl;
        number = temp->number;
    }

    return number;

}

Node *insert(Node *parent, int input) {

    if(parent == nullptr) {

        return new Node(input);

    }
    if(input > parent->number) {
        parent->right = insert(parent->right, input);
    }
    else if (input < parent->number) {

        parent->left = insert(parent->left, input);
    
    }

    return parent;
            
}

int inorder_successor(Node *parent) {
    int number = 0;

    parent = parent->left;
    cout << "inorder successor -- parent->number: " << parent->number << endl;

    while(parent->right != nullptr) {

        parent = parent->right;


    }

    number = parent->number;
    return number;
}

Node *remove(Node *parent, int input) {

    if(parent == nullptr) {
        return nullptr;
    }

    if(parent != nullptr) {
        cout << "Delete function current parent node: " << parent->number << endl;
    }

    if(input < parent->number) {

        parent->left = remove(parent->left, input);
        cout << "parent->left call returns here -- parent->number: " << parent->number << endl;

    }
    else if(input > parent->number) {
        parent->right = remove(parent->right, input);
        cout << "parent->right call returns here -- parent->number: " << parent->number << endl;
    }
    else {

        cout << "Found the node -- parent->number: " << parent->number << endl;
        if(parent->left == nullptr) {

            Node *temp = parent->right;
            delete parent;
            return temp;

        }
        else if(parent->right == nullptr) {

            Node *temp = parent->left;
            delete parent;
            return temp;

        }
        else {

            int number = inorder_successor(parent);

            cout << "inorder successor: " << number << endl;

            parent->number = number;

            parent->left = remove(parent->left, number);
            return parent;

        }
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

void preorder_print(Node *parent) {
    if(parent == nullptr) {
        return;
    }

    cout << parent->number << ", ";
    preorder_print(parent->left);
    preorder_print(parent->right);
}

void postorder_print(Node *parent) {
    if(parent == nullptr) {
        return;
    }

    postorder_print(parent->left);
    postorder_print(parent->right);
    cout << parent->number << ", ";
}


int main(void) {

    Node *root = new Node(20);

    // root = insert(root, 12);
    root = insert(root, 13);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 43);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 41);
    // root = insert(root, 8);
    // root = insert(root, 11);


    // root = remove(root, 9);
    // int newnode = search(root, 9);

    inorder_print(root);
    cout << endl << "preorder" << endl;
    preorder_print(root);
    cout << endl << "postorder" << endl;
    postorder_print(root);
    cout << endl;
    return 0;
}
