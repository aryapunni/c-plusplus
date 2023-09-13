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
class Node;
void inorder_print(Node *parent);

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

void nest_list_print(vector<vector<int>> input) {


    if(input.size() == 0) {
        cout << "{}" << endl;
        return;
    }

    cout << "{" ;

    for(int i = 0; i < input.size(); i++) {

        cout << "{";

        for(int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << ", " ;
        }

        cout << "}, ";

    }

    cout << "}" << endl;
}

class Queue{
    private:
        vector<Node *> addresses;
        int front = 0;
        int rear = -1;
        int size = 0;

    public:
        Queue() {

            addresses = {};
            front = 0;
            rear = -1;
            size = 0;

        }

        void enqueue(Node *address) {
            addresses.push_back(address);
            rear++;
            size++;
        }

        Node *dequeue() {

            if(size == 0) {
                return nullptr;
            }
            Node *address = addresses[front];
            front++;
            size--;
            return address;
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
            for(int i = front; i <= rear; i++) {

                cout << addresses[i] << ", ";
                
            }

            cout << endl;
        }

        int length() {
            return size;
        }
};


class Node{
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

        Node *insert(Node *root, vector<int> input) {

            Queue q = Queue();
            vector<int>::iterator ptr;

            q.enqueue(root);
            cout << "input[0]: " << input[0] << endl;
            root->number = input[0];

            cout << "inorder print of root: ";
            inorder_print(root);
            cout << endl;

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

                cout << "Queue: ";
                q.print();
                cout << "inorder print of root: ";
                inorder_print(root);
                cout << endl;
                cout << endl;

            }
            listprint(input);
            return root;

        }

};


void inorder_print(Node *parent) {
    if(parent == nullptr) {
        return;
    }

    inorder_print(parent->left);
    cout << parent->number << ",";
    inorder_print(parent->right);
}


void levelorder(Node *parent) {

    Queue q = Queue();
    vector<vector<Node*>> addresses;
    vector<vector<int>> values;

    q.enqueue(parent);


    while(!(q.is_empty())) {

        int size = q.length();
        vector<Node *> level_vector;
        vector<int> value_vect;

        for(int i = 0; i < size; i++) {

            Node *temp = q.dequeue();
            level_vector.push_back(temp);

            if(temp->left != nullptr) {

                q.enqueue(temp->left);
            }

            if(temp->right != nullptr) {
                
                q.enqueue(temp->right);
            }

        }

        for(int i = 0;i < level_vector.size(); i++) {
            value_vect.push_back(level_vector[i]->number);
        }

        values.push_back(value_vect);

    }

    nest_list_print(values);

}


int main(void) {

    Node root = Node();
    root.number = 0;

    inorder_print(&root);
    cout << endl;

    vector<int> input = {20, 10, 40, 8, 13, 43, 11, 41};

    root.insert(&root, input);

    levelorder(&root);


    return 0;
}
