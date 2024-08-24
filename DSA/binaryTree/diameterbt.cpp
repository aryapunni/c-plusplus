#include <algorithm>
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
        int data;
        Node *left;
        Node *right;

        Node() {
            left = nullptr;
            right = nullptr;
        }

        Node(int input) {
            data = input;
            left = nullptr;
            right = nullptr;
        }


};


int hight(Node *parent) {

    int lh;
    int rh;


    if(parent == nullptr) {
        return -1;
    }


    lh = hight(parent->left);


    rh = hight(parent->right);
    
    cout << parent->data << endl;
    
    cout << "left hight: " << lh << endl;
    
    cout << "right hight: " << rh << endl;

    cout << "return value: " << max(lh, rh) + 1 << endl;

    return max(lh, rh) + 1;


}

int diameter(Node *parent) {

    int lhs = 0;
    int rhs = 0;
    int ld = 0;
    int rd = 0;
    int d_local = 0;

    if(parent == nullptr) {
        return -1;
    }

    if(parent->left) {
        cout << "parent: " << parent->data << "  parent->left: " << parent->left->data << endl;
    }


    if(parent->right) {
        cout << "parent: " << parent->data << "  parent->left: " << parent->right->data << endl;
    }


    lhs = hight(parent->left);
    rhs = hight(parent->right);

    cout << "LHS: " << lhs << "  RHS: " << rhs << endl;

    ld = diameter(parent->left);
    rd = diameter(parent->right);

    cout << "ld: " << ld << " rd: " << rd << endl;




    return max(lhs + rhs + 1, max(ld, rd));
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



void inorder_print(Node * parent) {
    if(parent == nullptr) {
        return;
    }

    inorder_print(parent->left);
    cout << parent->data << ", ";
    inorder_print(parent->right);
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

    int h = hight(root);
    cout << "hight: " << h << endl;

    int d = diameter(root);
    cout << d << endl;




    return 0;
}

