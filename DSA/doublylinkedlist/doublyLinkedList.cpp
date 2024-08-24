#include <cstdlib>
#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Node {
    public:
        string name;
        Node *prev = nullptr;
        Node *next = nullptr;

        Node(string input) {
            name = input;
        }

        Node(string input, Node *prev_node, Node *next_node) {
            name = input;
            prev = prev_node;
            next = next_node;
        }

};

class Namelist {

    private:

        Node *head = nullptr;
        Node *tail = nullptr;
        int length = 0;

    public:

     Namelist() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        void push_front(string name) {
            Node *newnode = new Node(name);

            if(head == nullptr) {
                head = newnode;
                tail = newnode;
                length++;
                return;
            }

            Node *temp = head;
            newnode->next = temp;
            temp->prev = newnode;
            head = newnode;
            length++;
        }

        void append(string name) {
            Node *newnode = new Node(name);

            if(head == nullptr) {
                head = newnode;
                tail = newnode;
                length++;
                return;
            }

            Node *temp = tail;
            newnode->prev = temp;
            temp->next = newnode;
            tail = newnode;
            length++;
        }

        void print() {
            Node *temp = head;
            cout << "{" ;
            while(temp != nullptr) {
                cout << temp->name << ", ";
                temp = temp->next;
            }

            cout << "}" << endl;
        }

        void tail_print() {
            Node *temp = tail;
            cout << "{" ;
            while(temp != nullptr) {
                cout << temp->name << ", " ;
                temp = temp->prev;
            }
            cout << "}" << endl;

        }

        void remove_node (string name) {

            Node *temp = head;

            if(temp == nullptr) {
                cout << "Linked list is empty" << endl;
                return;
            }

            while(temp->name != name) {
                temp = temp->next;
                if(temp == nullptr) {
                    cout << "No such name exists in this linked list" << endl;
                    return;
                }
            }

            Node *nextnode = temp->next;
            if(nextnode == nullptr) {
                cout << "Node to be deleted is tail" << endl;
                temp->prev->next = nullptr;
                delete temp;
                return;
            }
            else if(temp == head) {
                cout << "Node to be deleted is head node" << endl;
                head = nextnode;
                delete temp;
                return;
            }
            cout << "delete temp node" << endl;
            temp->prev->next = nextnode;
            nextnode->prev = temp->prev;
            delete temp;

        }

        void add_at_node(string name, string name_location) {

            Node *temp = head;
            Node *insert_node = nullptr;
            Node *location_node = nullptr;

            if(temp == nullptr) {
                cout << "Linked list is null" << endl;
                return;
            }

            while(temp->name != name_location) {

                if(temp->name == name) {
                    cout << "Found the insert node" << endl;
                    insert_node = temp;
                }

                temp = temp->next;

                if(temp == nullptr) {
                    cout << "location does not exist" << endl;
                    return;
                }
            
            }

            if(temp->name == name_location) {
                cout << "Found the location node" << endl;
                location_node = temp;
                if(insert_node == nullptr) {
                    cout << "Inserting node not found before location node" << endl;

                    while (temp->name != name) {

                        temp = temp->next;

                        if(temp == nullptr) {
                            cout << "No existing node as insert node" << endl;
                            break;
                        }
                    
                    }

                    if((temp != nullptr) && (temp->name == name)) {

                        if(temp->next == nullptr) {
                            temp->prev->next = nullptr;
                            delete temp;
                            
                        }
                        else {

                           Node *next_node = temp->next;
                            temp->prev->next = next_node;
                            next_node->prev = temp->prev;
                            delete temp;
                        }

                    }
                }
            }

            cout << "insert this node at the correct location" << endl;
            insert_node = new Node(name);
            Node *prev_node = location_node->prev;
            location_node->prev = insert_node;
            insert_node->next = location_node;
            insert_node->prev = prev_node;
            prev_node->next = insert_node;
            print();
        
        }

        void remove_all_node_with_name(string name) {

            Node *temp = head;

            if(temp == nullptr) {
                cout << "This list seems to be empty" << endl;
                return;
            }

            while(temp != nullptr) {

                if(temp->name == name) {
                    if(temp == head) {
                        cout << "head is given node to be deleted" << endl;
                        Node *nextnode = temp->next;
                        nextnode->prev = nullptr;
                        head = nextnode;
                        delete temp;
                        temp = head;

                    }
                    else if(temp->next == nullptr) {
                        cout << "tail is given node to be deleted" << endl;
                        Node *prev_node = temp->prev;
                        prev_node->next = nullptr;
                        tail = prev_node;
                        delete temp;
                        temp = tail;
                    }
                    else {

                        Node *nextnode = temp->next;
                        temp->prev->next = nextnode;
                        nextnode->prev = temp->prev;
                        delete temp;
                        temp = nextnode->prev;
                    }
                }

                temp = temp->next;
            }


        }

        void insert_at_index(string name, int index) {

            if(index < 0 || index >= length) {
                cout << "given index is not in the range of linked list" << endl;
                return;
            }

            if(head == nullptr) {
                cout << "Linked list seems to be empty" << endl;
                return;
            }

            Node *temp = head;
            while (temp->name != name) {
                temp = temp->next;
                if(temp == nullptr) {
                    cout << "No such node exist in the list" << endl;
                    break;
                }
                
            }
 

            //if the node is equal to the length of the list
            if(index == length) {

               //if temp == nullptr, there is no such node already 
                // existing in the list
                if(temp == nullptr) {

                    Node *new_node = new Node(name);
                    new_node->prev = tail;
                    tail->next = new_node;
                    tail = new_node;
                    length++;
                }
                else if(temp == head) {
                    Node *nextnode = temp->next;
                    nextnode->prev = nullptr;
                    head = nextnode;

                    temp->next = nullptr;
                    temp->prev = tail;
                    tail->next = temp;
                    tail = temp;

                }
                else if(temp == tail) {
                    cout << "Node is in correct position" << endl;
                    return;
                }
                //Node already exists 
                //shift the existing node to end
                else {
                    Node *nextnode = temp->next;
                    nextnode->prev = temp->prev;
                    temp->prev->next = nextnode;

                    temp->next = nullptr;
                    temp->prev = tail;
                    tail->next = temp;
                    tail = temp;
                }

            }
            else if(index == 0) {

                if(temp == nullptr) {
                    Node *new_node = new Node(name);
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                    length++;
                }
                else if(temp == head) {

                    cout << "Node is in correct position" << endl;
                    return;

                }
                else if(temp == tail) {
                    Node *prev_node = temp->prev;
                    prev_node->next = nullptr;
                    tail = prev_node;

                    temp->prev = nullptr;
                    temp->next = head;
                    head->prev = temp;
                    head = temp;
                }
                else {
                    Node *nextnode = temp->next;
                    nextnode->prev = temp->prev;
                    temp->prev->next = nextnode;

                    temp->next = head;
                    temp->prev = nullptr;
                    head->prev = temp;
                    head = temp;
                }
            }
            else {
                Node *position_node = head;
                for(int i = 1; i <= index; i++) {


                    position_node = position_node->next;
                    if(position_node == nullptr) {
                        break;
                    }
                }

                if(position_node->name == name) {
                    cout << "name is in correct position" << endl;
                    return;
                }



                if(temp == nullptr) {

                    Node *new_node = new Node(name);
                    Node *prev_node = position_node->prev;
                    new_node->next = position_node;
                    new_node->prev = prev_node;
                    prev_node->next = new_node;
                    position_node->prev = new_node;
                    length++;

                }
                else if(temp == head) {

                    Node *headnode = temp->next;
                    headnode->prev = nullptr;
                    head = headnode;

                    Node *prev_node = position_node->prev;
                    prev_node->next = temp;
                    temp->next = position_node;
                    temp->prev = prev_node;
                    position_node->prev = temp;


                }
                else if (temp == tail) {
                    Node *tailnode = temp->prev;
                    tailnode->next = nullptr;
                    tail = tailnode;

                    Node *prev_node = position_node->prev;
                    prev_node->next = temp;
                    temp->next = position_node;
                    temp->prev = prev_node;
                    position_node->prev = temp; 
                
                }
                else {

                    Node *prev_node = temp->prev;
                    prev_node->next = temp->next;
                    temp->next->prev = prev_node;

                    Node *position_prev = position_node->prev;
                    temp->next = position_node;
                    temp->prev = position_prev;
                    position_prev->next = temp;
                    position_node->prev = temp;



                }
            }


        }

};


int main(void) {

    Namelist list = Namelist();
    list.append("Alekhya");
    list.append("Midhun");
    list.append("Arya");
    list.append("Jyothis");
    list.append("Velunni");
    list.append("Bindu");

    list.print();
    list.tail_print();

    // list.add_at_node("Jyothis", "Midhun");

    // list.remove_node("Velunnii");
    // list.remove_all_node_with_name("Arya");
    list.insert_at_index("Alekhya", 0);
    list.print();
    return 0;
}

