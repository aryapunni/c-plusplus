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

Node *sortedArrayBST(vector<int> input, Node *parent, int left, int right, string call) {
    if(left > right) {
        return nullptr;
    }

    int mid = (right - left)/2 + left;

    // cout << mid << "\t" << input[mid] << endl;
    parent = new Node(input[mid]);
    // cout << parent->data << endl;
    cout << call << endl;
    cout << "parent: " << parent->data << "  left: " << left << "  right: " << right << "  mid: " << mid << endl;

    parent->left = sortedArrayBST(input, parent->left, left, mid - 1, "left call");
    parent->right = sortedArrayBST(input, parent->right, mid + 1, right, "right call");

    return parent;
}

void inorder_print(Node *parent) {
    if(parent == nullptr) {
        return;
    }

    cout << parent->data << ", ";
    inorder_print(parent->left);
    inorder_print(parent->right);
}


int main(void) {

    vector<int> data = {1, 2, 3, 4, 5, 6, 7};

    Node *root = new Node();

    root = sortedArrayBST(data, root, 0, 6, "first call");

    inorder_print(root);
    cout << endl;

    return 0;

}

