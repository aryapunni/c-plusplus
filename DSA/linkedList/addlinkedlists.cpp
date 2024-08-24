#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;

void print_vector(vector<int> input) {
    if(input.empty()) {
        cout << "{}";
    }
    else {
        cout << "{\t";
        for(int i = 0; i < input.size(); i++) {
             cout << input[i] << "\t";
        }
        cout << "}\n";
    }
}

class Node {

    public:
        int digit;
        Node *next;

    
        Node(int input) {
            digit = input;
            next = nullptr;
        }

        Node(int input, Node *next) {
            digit = input;
            next = next;
        }

};

class NumList {

    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int length;

    public:
        NumList() {
            head = nullptr;
            tail = head;
            length = 0;

        }

        NumList(vector<int> input) {

            Node *head = nullptr;
            Node *tail = nullptr;


            vector<int>::iterator digit;

            for(digit = input.begin(); digit < input.end(); digit++) {
                push_front(*digit);
            }
        }

        Node * head_node() {
            return head;
        }

        void push_front(int digit) {


            Node *new_node = new Node(digit);

            if(head == nullptr) {
                head = new_node;
                tail = new_node;
                length++;
                return;
            }

            Node *temp = head;
            head = new_node;
            new_node->next = temp;
            length++;
            
        }

        void print() {
            Node *temp = head;

            cout << "{ ";

            while(temp != nullptr) {

                cout << temp->digit << " , ";
                temp = temp->next;
                
            }

            cout << "}" << endl;

        }

        void append(int digit) {

            Node *new_node = new Node(digit);

            if(head == nullptr) {
                head = new_node;
                tail = new_node;
                length++;
                return;
            }

            Node *temp = tail;
            tail->next = new_node;
            tail = new_node;
            length++;
        }


};

NumList add_list(NumList *list1, NumList *list2) {

    // list1->print();
    // list2->print();

    NumList result = NumList();
    int digit1 = 0;
    int digit2 = 0;
    int sum = 0;
    int carry = 0;

    Node *temp_list1 = list1->head_node();
    Node *temp_list2 = list2->head_node();

    while((temp_list1 != nullptr) || (temp_list2 != nullptr)) {

        if(temp_list1 != nullptr) {
            digit1 = temp_list1->digit;
        }
        else {
            digit1 = 0;
        }

        if(temp_list2 != nullptr) {
            digit2 = temp_list2->digit;
        }
        else {
            digit2 = 0;
        }

        sum = digit1 + digit2 + carry;

        if(sum > 9) {
            carry = 1;
            sum = sum - 10;
        }
        else {
            carry = 0;
        }

        result.append(sum);

        if(temp_list1 != nullptr) {

            temp_list1 = temp_list1->next;
        }

        if(temp_list2 != nullptr) {

            temp_list2 = temp_list2->next;
        }
    }

    if(carry > 0) {
        result.append(carry);
    }

    result.print();

    return *list1;

}

int main(void) {

    NumList list = NumList();

    list.append(3);
    list.append(4);
    list.append(2);
    list.print();

    vector<int> numbers = {4, 6, 5};
    NumList list1 = NumList(numbers);
    list1.print();

    list = add_list(&list, &list1);
    return 0;
}

