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
#include <limits>

using namespace std;


class Node;



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

        Node *insert(Node *root, vector<int> input) {

            Queue q = Queue();
            vector<int>::iterator ptr;

            q.enqueue(root);
            cout << "input[0]: " << input[0] << endl;
            root->data = input[0];


            for(ptr = input.begin() + 1; ptr <= input.end() - 1; ptr++) {
                // cout << *ptr << ", ";

                Node *temp = q.dequeue();

                temp->left = new Node(*ptr);
                if(ptr < input.end() - 1) {

                    ptr++;
                    temp->right = new Node(*ptr);
                }

                q.enqueue(temp->left);
                q.enqueue(temp->right);

               cout << endl;


            }
            return root;

        }

};


Node *sortedArrayBST(vector<int> input, Node *parent, int left, int right) {
    if(left > right) {
        return nullptr;
    }

    int mid = (right - left)/2 + left;

    parent = new Node(input[mid]);
    // cout << "parent: " << parent->data << "  left: " << left << "  right: " << right << "  mid: " << mid << endl;

    parent->left = sortedArrayBST(input, parent->left, left, mid - 1);
    parent->right = sortedArrayBST(input, parent->right, mid + 1, right);

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


bool valid_bst(Node *parent, int max, int min, string call) {

    if(parent == nullptr) {
        return true;
    }

    cout << call << endl;
    cout << "parent: " << parent->data << "  max: " << max << "  min: " << min << endl;

    if((parent->data > min) && (parent->data < max)) {

        return (valid_bst(parent->left, parent->data, min, "left call maximum changed") &&

        valid_bst(parent->right, max, parent->data, "right call minimum changed"));

    }
    else {
        return false;
    }
    // return true;

}


int main(void) {
    int imin = numeric_limits<int>::min(); 
    int imax = numeric_limits<int>::max();

    cout << imin << "\t" << imax << endl;

    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    Node *root = new Node();

    root = sortedArrayBST(input, root, 0, 6);

    bool truth = valid_bst(root, imax, imin, "First call");

    cout << "True or false: " << truth << endl;

    Node *newroot = new Node();
    newroot->insert(newroot, input);

    inorder_print(newroot);
    cout << endl;

    truth = valid_bst(newroot, imax, imin, "First call");
    cout << "True or false: " << truth << endl;



    return 0;
}

