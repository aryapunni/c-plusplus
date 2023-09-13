#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;
class Node;
void print_vector(vector<Node *> &input);


void swap(Node **a, Node **b) {

    Node **temp = a;
    a = b;
    b = temp;

}




class Node{
    public:
        int job;
        int priority;

        Node() {
            job = 0;
            priority = 0;
        }

        Node(int job_input, int prio_input) {
            job = job_input;
            priority = prio_input;
        }

};

class Heap{
    private:
        vector<Node *> heap;


        vector<Node *> bubble_up(vector<Node *> &input, int size, int index) {
            int new_value_index = index;
            int parent_index = (index - 1) / 2;

            cout << "input vector: " ;
            print_vector(input);

            cout << "input: [" << input[index]->job << ", " << input[index]->priority << "]" << endl;


            if((new_value_index > 0) && (input[new_value_index]->priority < input[parent_index]->priority)) {
                new_value_index = parent_index;
            }

            if(new_value_index != index) {
                cout << "swapping.... [" << input[new_value_index]->job << ", " <<  input[new_value_index]->priority << "] and [" << input[index]->job << ", " <<  input[index]->priority << "]" << endl;
                print_vector(input);
                swap(input[new_value_index], input[index]);
                cout << "swapped [" << input[new_value_index]->job << ", " <<  input[new_value_index]->priority << "] and [" << input[index]->job << ", " <<  input[index]->priority << "]" << endl;
                print_vector(input);
                bubble_up(input, size, new_value_index);
                
            }


            return input;
        }



        vector<Node *> bubble_down(vector<Node *> &input, int size, int index) {


            cout << endl << "----------------------------------------------------------------" << endl << endl;
            cout << "input: [" << input[index]->job << ", " << input[index]->priority << "]" << endl;

            int low_priority_index = index;
            int left_child_index = (2 * index) + 1;
            int right_child_index = (2 * index) + 2;
            cout << "----------------------------------------------------------------" << endl << endl;
            cout << "size: " << size << endl;
            cout << "lowpriorityindex: " << low_priority_index << ", leftchildindex: " << left_child_index << ", rightchildindex: " << right_child_index << endl;
            if(left_child_index < size && low_priority_index < size) {


                cout << "low priority index->priority: " << input[low_priority_index]->priority << ", left child index->priority: " << input[left_child_index]->priority << endl;

               if(input[low_priority_index]->priority > input[left_child_index]->priority) {
                    low_priority_index = left_child_index;
                    cout << "low priority index changed to left child" << endl;

                }
            }

            if(low_priority_index < size && right_child_index < size) { 

                cout << "low priority index->priority: " << input[low_priority_index]->priority << ", right child index->priority: " << input[right_child_index]->priority << endl;
                
                if((low_priority_index < size) && (input[low_priority_index]->priority > input[right_child_index]->priority)) {

                    low_priority_index = right_child_index;

                    cout << "low priority index changed to right child" << endl;
                }
 
            cout << endl << "----------------------------------------------------------------" << endl << endl;

            }


            if(low_priority_index != index) {
                print_vector(input);
                cout << "swapping.... [" << input[low_priority_index]->job << ", " <<  input[low_priority_index]->priority << "] and [" << input[index]->job << ", " <<  input[index]->priority << "]" << endl;
                swap(input[index], input[low_priority_index]);
                cout << "swapped [" << input[low_priority_index]->job << ", " <<  input[low_priority_index]->priority << "] and [" << input[index]->job << ", " <<  input[index]->priority << "]" << endl;
                print_vector(input);
                bubble_down(input, size, low_priority_index);
            }

            return input;
            
        }

    public:
        Heap() {

            heap = {};
        }

        Heap *enqueue(Node *input, Heap * hp) {

            cout << endl << "------------------------enqueue------------------------------" << endl;
            heap.push_back(input);
            print_vector(heap);

            heap = bubble_up(heap, heap.size(), heap.size() - 1);
            // print_vector(heap);

            return hp;
        }

        Heap *build(vector<Node *> &input, Heap *hp) {
            print_vector(input);
            for(int i = (input.size() / 2) - 1; i >= 0; i--) {

                input = bubble_down(input, input.size(), i);

            }

            print_vector(input);
            heap = input;
            print_vector(heap);
            return hp;
        }

        Node *extract() {

            cout << endl << "----------------------------EXTRACT----------------------------------------" << endl;
            print_vector(heap);
            Node *result = heap[0];
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            bubble_down(heap, heap.size(), 0);
            print_vector(heap); 

            return result;
        }


};

void print_vector(vector<Node *> &input) {

    cout << "{ ";

    if(input.empty()) {
        cout << "}" << endl;
        return;
    }

    for(int i = 0; i < input.size(); i++) {
        cout << "[ " << input[i]->job << ", " << input[i]->priority << " ], ";
    }

    cout << "}" << endl;

}

int main(void) {

    Node *node_1 = new Node(8, 1);
    Node *node_2 = new Node(4, 2);
    Node *node_3 = new Node(5, 1);
    Node *node_4 = new Node(6, 4);
    Node *node_5 = new Node(7, 3);
    Node *node_6 = new Node(9, 8);

    vector<Node *> input = {node_3, node_6, node_1, node_5, node_4, node_2};



    Heap *hp = new Heap();

    hp->build(input, hp);

    Node *node_7 = new Node(11, 0);

    hp->enqueue(node_7, hp);

    Node *node = hp->extract();
    cout << "[" << node->job << ", " << node->priority << "]" << endl;


    return 0;
}

