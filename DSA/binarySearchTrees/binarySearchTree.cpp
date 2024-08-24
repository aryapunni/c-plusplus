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
        int number;
        Node *left;
        Node *right;

        Node(int input) {
            number = input;
            left = nullptr;
            right = nullptr;
        }
};

class Tree {
    private:

        Node *root = nullptr;

    public:
        Tree() {
            root = nullptr;
        }

        void insert(int number) {

            Node *newnode = new Node(number);

            if(root == nullptr) {

                root = newnode;
                return;

            }

            Node *temp = root;
            Node *prev = root;

            while(temp != nullptr) {
                if(temp->number > number) {
                    prev = temp;
                    // cout << "number is less than parent node" << endl;
                    temp = temp->left;
                }
                else {
                    prev = temp;
                    // cout << "number is greater than parent node" << endl;
                    temp = temp->right;
                }
            }

            if((prev != nullptr) && (temp == nullptr)) {
                temp = newnode;
                if(prev->number > temp->number) {
                    prev->left = temp;
                }
                else {
                    prev->right = temp;
                }
            }

           
        }

        Node *find(int number) {

            Node *temp = root;
            Node *prev = temp;

            while(temp != nullptr) {
                prev = temp;
                if(number > temp->number) {
                    temp = temp->right;
                }
                else if(number < temp->number) {
                    temp = temp->left;
                }
                else {
                    cout << temp->number << endl;
                    return temp;

                }
            }
            if(temp == nullptr) {
                cout << "Value not in the tree. Returning null" << endl;
            }
            return temp;
        }

        void remove(int number) {

            Node *temp = root;

            Node *prev = temp;

            Node *parent = nullptr;

            if(root == nullptr) {
                return;
            }

            // Step 1: Find number

            while(temp != nullptr) {


                if(number < temp->number) {
                    prev = temp;
                    // cout << temp->number << endl;
                    temp = temp->left;
                }
                else if(number > temp->number) {
                    prev = temp;
                    // cout << temp->number << endl;
                    temp = temp->right;
                }
                else {
                    cout << "Found the number: " << temp->number << endl;
                    break;
                }
            }



            if(temp != nullptr) {

                if(temp->number == number) {

                    parent = prev;
                    cout << "parent " << parent->number << endl;
                    cout << "Node " << temp->number << endl;

                }

            }
            else {
                cout << "No such number" << endl;
                return;
            }

            // Step 2: delete -- 3 cases
            // 1. Node is a leaf node
            // 2. Node has one child
            // 3. Node has two children

            if((temp->left == nullptr) && (temp->right == nullptr)) {

                cout << "easy deletion" << endl;
                // Leaf node -- Make parent node next equal to null

                if(parent->left == temp) {
                    parent->left = nullptr;
                    delete temp;
                }
                else if(parent->right == temp) {
                    parent->right = nullptr;
                    delete temp;
                }

            }
            else if((temp->left != nullptr) && (temp->right == nullptr)) {

                cout << "SINGLE NODE left not null." << endl;
                // attach temp->left node to parent->left
                parent->left = temp->left;
                delete temp;


            }
            else if((temp->left == nullptr) && (temp->right != nullptr)) {

                cout << "SINGLE NODE right not null." << endl;
                // attach temp->right node to parent->right
                parent->right = temp->right;
                delete temp;

            }
            else if ((temp->left != nullptr) && (temp->right != nullptr)) {

                cout << "DIFFICULT Both nodes are not null" << endl;
                // 3 steps: -- 1. Find the right most element in the left tree
                //          -- 1. OR left most element in the right side of the node
                //          -- 2. Replace that number in the node to be deleted
                //          -- 3. delete right most element in the left tree OR 
                //                        left most element in the right tree


                // In this implimentation we are choosing 
                // right most element in the left tree

                Node *replaceNode = temp->left;
                int replaceNumber = 0;

                while(replaceNode->right != nullptr) {

                        
                    replaceNode = replaceNode->right;


                }

                // cout << replaceNode->number << endl;

                replaceNumber = replaceNode->number;

                remove(replaceNumber);

                temp->number = replaceNumber;

            
            }
            else {
                cout << "Will it come here test" << endl;
            }


        }


        void print() {


        }

    
};


int main(void) {

    Tree bst = Tree();

    bst.insert(5);
    bst.insert(7);
    bst.insert(4);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);

    bst.find(34);

    bst.print();

    // bst.remove(3);
    // bst.remove(3);
    // bst.remove(4);
    // bst.remove(4);
    bst.remove(7);
    bst.remove(8);
    // bst.remove(6);


    return 0;
}

