#include<iostream>
#include <string>
#include <vector>
#include <map>



using namespace std;



class Node {

    public:
        string name;
        Node *next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    } 

    Node(string name, Node *next) {
        this->name = name;
        this->next = next;
    }



};


class Linkedlist {

    private:
        Node *head;
        Node *tail;
        Node *node_iterator;
        int length;

    public:
        Linkedlist() {

            head = nullptr;
            tail = head;
            length = 0;
        }

        Linkedlist(vector<string> input) {

            head = nullptr;
            tail = head;
            length = 0;

            for(vector<string>::iterator name = input.begin(); name < input.end(); name++) {

                push_front(*name);

            }

        }


        void change_head(Node *nodAddr) {
            head = nodAddr;
        }


        Node *head_node() {
            return head;
        }

        void print() {

            cout << "{ ";
            Node *temp = head;
            while(temp != nullptr) {
                cout << temp->name << " , ";
                temp = temp->next;
            }
            cout << " } ";
            cout << endl;
        }

        void push_front(string name) {

            // creating a new node to pushfornt as head pointing to next
            Node *newNode = new Node(name, head);

            //if head points to null
            //initialise tail as the new node
            if(head == nullptr) {
                tail = newNode;
            }

            //change head to the new node added
            head = newNode;

            //increment length of list
            length++;


        }

        void append(string name) {


            //creating a new node with null pointer as next node
            Node *newNode = new Node(name);
            
            // if this is the first node
            //initialise head and tail as the
            //address of new node
            if(head == nullptr) {

                head = newNode;
                tail = newNode;
                length++;
                return;

            }
            
            //Add new node created at the tail
            //change tail pointer as the newly
            //created node
            tail->next = newNode;
            tail = newNode;
            length++;   



        }

        void add_at_index(int index, string name) {

            //return when the index is not in between 0 and length
            if((index < 0) || (index > length)) {
                return;
            }
            //if index is 0
            //to add value at head
            //call function push_front
            else if(index == 0) {
                push_front(name);
            }
            //if index is at tail
            //call append function to 
            //add value at the end
            else if (index == length) {

                append(name);
            
            }
            else {
                Node *temp = head;

                Node *newNode = new Node(name);

                for(int i = 0; i < index - 1; i++) {
                    temp = temp->next;
                }

                // cout << "temp : " << temp->name << " temp->next.name : " << temp->next->name << endl;

                newNode->next = temp->next;
                temp->next = newNode;
                length++;

            }


        }

        int len() {

            return length;
        }

        string get_index(int index) {

            if((index < 0) || (index >= length)) {
                return "";
            }

            Node *temp = head;

            for(int i = 0; i < index; i++) {

                temp = temp->next;

            }

            cout << "Name at index " << index << " is " << temp->name << endl;
            return temp->name;

        }

        void delete_at_index(int index) {

             //return when the index is not in between 0 and length
            if((index < 0) || (index >= length)) {
                return;
            }
            //if index is 0
            //to delete value at head
            //change address of head to head->next
            else if(index == 0) {
                Node *temp = head;
                head = head->next;
                delete temp;
                length--;
            }
            else if(index == length - 1) {

                Node *current_node = head;
                Node *prev_node = tail;
                while(current_node != tail) {
                    prev_node = current_node;
                    current_node = current_node->next;
                }
                cout << "prev node: " << prev_node->name << "\tcurrent Node: " << current_node->name << endl;
                prev_node->next = nullptr;
                delete current_node;
                length--;
                tail = prev_node;

            }
            else {
                Node *temp = head;
                Node *prev_node = head;
                Node *current_node = head;
                Node *next_node = nullptr;
                

                for(int i = 0; (i < index) && (current_node != tail); i++) {
                    prev_node = current_node;
                    current_node = current_node->next;
                    // next_node = current_node->next;
                    cout << "prev node : " << prev_node->name << "\tcurrent node : " << current_node->name << endl;

                } 
                cout << "outside Loop" << endl;
                next_node = current_node->next;
                prev_node->next = next_node;
                delete current_node;
                length--;
            }


        }


};


void print_map(map<Node *, int> test) {
    map<Node *, int>::iterator itr; 
    for(itr = test.begin(); itr != test.end(); ++itr) {
        cout << "\t" << itr->first << "\t" << itr->second <<"\n";
    }
    cout << endl;
}



Linkedlist delete_duplicates(Linkedlist *list) {

    Node *temp = list->head_node();
    Node *prev_node = temp;
    Node *current_node = temp->next;
    string current_name = current_node->name;
    string prev_name = prev_node->name;

    while(current_node != nullptr) {

        current_name = current_node->name;


        if(current_name == prev_name) {

            prev_node->next = current_node->next;
            delete current_node;
            current_node = prev_node->next;

        } 
        else {
            prev_name = current_name;
            prev_node = current_node;
            current_node = current_node->next;

        }

    }


    return *list;
}


Node *reverse_list(Linkedlist *list) {

    list->print();
    Node *prev_node = nullptr;
    Node *current_node = list->head_node();
    Node *next_node = current_node->next;

    

    while (current_node != nullptr) {

        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
        if(current_node != nullptr) {

            next_node = next_node->next;
        }

    }
   return prev_node;
}


Linkedlist reverse(Linkedlist *list) {

    Linkedlist reversed_list = Linkedlist();
    Node *temp = list->head_node();

    while(temp->next != nullptr) {
        temp = temp->next;
    }

    reversed_list.push_front(temp->name);

    Node *list_head = list->head_node();
    Node *reversed_list_head = reversed_list.head_node();

    while(list_head != temp) {

        Node *new_node = new Node(list_head->name);

        Node *next_node = reversed_list_head->next;
        reversed_list_head->next = new_node;
        new_node->next = next_node;
        list_head = list_head->next;

    }

    return reversed_list;
}


int detect_cycle(Linkedlist *list) {

    map<Node *, int> address_map;

    Node *temp_head = list->head_node();

    int i = 0;

    while((temp_head != nullptr)) {

        if(address_map.find(temp_head) == address_map.end()) {
            address_map[temp_head] = i;
            i++;
            temp_head = temp_head->next;

            print_map(address_map);
        }
        else {
            print_map(address_map);
            return address_map[temp_head];
        }

    }
    print_map(address_map);

    return -1;
}


int cycle_detection(Linkedlist *list) {


    int cycle = 0;

    Node *fast_ptr = list->head_node();
    Node *slow_ptr = fast_ptr;

    while((fast_ptr != nullptr) || (slow_ptr != nullptr)) {
        fast_ptr = fast_ptr->next;
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
        cout << slow_ptr->name << "\t" << fast_ptr->name << endl;
        if(fast_ptr == slow_ptr) {
            cout << "Two pinters meet here" << endl;
            Node *newnode = list->head_node();

            while(newnode != slow_ptr) {

                newnode = newnode->next;
                slow_ptr = slow_ptr->next;
                cycle++;
                
                
            }

            cout << "cycle: " << cycle << endl;

            return 1;
        }
    }
    
    return 0;
}


int detect_duplicates(vector<int> input) {

    map<int, int> number_map;

    for(int i = 0; i < input.size(); i++) {

        if(number_map.find(input[i]) == number_map.end()) {

            number_map[input[i]] = i;

        }
        else {
            return input[i];
        }

    }
    return -1;
}


int main(void) {

    Linkedlist list = Linkedlist();
    list.push_front("Arya");
    list.append("Chicku");
    list.push_front("Jyothis");
    list.append("Mali");
    list.push_front("Docker");
    list.push_front("Lottery");
    list.append("velunni");


    // list.get_index(4);

    list.add_at_index(0, "kukkachi");
    // list.print();
    list.add_at_index(list.len(), "mandhip");


    cout << "list length: " << list.len() << endl;
    // list.print();

    for(int i = 0; i < list.len(); i++) {

        cout << "--------------------------------------------------" << endl;
        list.print();

        cout << "Node index is:\t" << i << endl;

        list.delete_at_index(i);
        cout << "--------------------------------------------------" << endl;

    }


    list.print();
    cout << "list length: " << list.len() << endl;


    vector<string> newList = { "h", "h", "g", "g",  "f", "f",  "e",  "d",  "c",  "b",  "a", "a"};
    Linkedlist list_new = Linkedlist(newList);
    cout << list_new.len() << endl;
    list_new.print();
    list_new.append("i");
    list_new.print();
    cout << list_new.len() << endl;

    list_new = delete_duplicates(&list_new);
    list_new.print();

    list_new = reverse(&list_new);
    list_new.print();


    vector<string> names = {"Arya", "Jyothis", "Kochuraman", "Lalu", "Newton"};
    Linkedlist cycle = Linkedlist(names);

    cycle.print();

    Node *second_node = cycle.head_node();
    second_node = second_node->next;


    Node *end_node = cycle.head_node();

    while(end_node->next != nullptr) {
        end_node = end_node->next;
    }

    cout << second_node->name << "\t" << end_node->name << endl;

    end_node->next = second_node;


    int result = detect_cycle(&cycle);

    cout << "result: " << result << endl;


    vector<int> numbers = {1, 2, 3, 3};

    int value = detect_duplicates(numbers);
    cout << value << endl;

    vector<string> name_list = {"d", "c", "b", "a"};
    Linkedlist names_list = Linkedlist(name_list);

    Node *list_start = reverse_list(&names_list);

    while(list_start != nullptr) {
        cout << list_start->name << endl;
        list_start = list_start->next;
    }
    names_list.print();

    int val = cycle_detection(&cycle);
    return 0;

}