#include<iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;


void print_vector(vector<int> input) {
    cout << "{ ";

    if(input.empty()) {
        cout << "}" << endl;
        return;
    }

    for(int i = 0; i < input.size(); i++) {
        cout << input[i] << ", ";
    }

    cout << "}" << endl;
}

class Heap{
    private:
        vector<int> heap;
        int size = 0;

        vector<int> internal_nodes(vector<int> input) {
            int start = 0;
            int end = (input.size()/2) - 1;
            return {start, end}; 
        }

        void swap(int *a, int *b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }

        vector<int> *bubble_down(vector<int> &input, int index, int size) {

            int large_value_index = index;
            int left_child_index = (2*index + 1);
            int right_child_index = (2*index + 2);


            if((left_child_index < size) && (input[large_value_index] < input[left_child_index])) {
                large_value_index = left_child_index;
            }


            if((right_child_index < size) && (input[large_value_index] < input[right_child_index])) {
                large_value_index = right_child_index;
            }


            if(large_value_index != index) {

                swap(&input[large_value_index], &input[index]);


                bubble_down(input, large_value_index, size);

                
            }

            return &input;
        }

        vector<int> *bubble_up(vector<int> &input, int index, int size) {
            int new_value_index = index;
            int parent_index = (index - 1) / 2;

            if((new_value_index > 0) && (input[new_value_index] > input[parent_index])) {
                new_value_index = parent_index;
            }


            if(new_value_index != index) {
                swap(&input[index], &input[new_value_index]);

                bubble_up(input, new_value_index, size);
            }



            return &input;

        }

    public:
        Heap() {
            heap = {};
            size = 0;
        }

        Heap *build(Heap *hp, vector<int> input) {

            vector<int>::iterator ptr;
            int size = input.size();

            for(int i = (input.size()/2) - 1; i >= 0; i--) {

                bubble_down(input, i, size);
            }
            print_vector(input);

            heap = input;

            return hp;
        }

        Heap *insert(Heap *hp, int input) {

            heap.push_back(input);

            bubble_up(heap, heap.size() - 1, heap.size());

            print_vector(heap);

            return hp;
        }

        int remove() {

            int result = heap[0];
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            print_vector(heap);

            bubble_down(heap, 0, heap.size());
            print_vector(heap);
            return result;
        }

        int peek() {
            int result = heap[0];
            return result;
        }
};

int main(void) {

    Heap *hp = new Heap();
    vector<int> input = {4, 7, 3, 0, 9, 3, 2, 6};

    hp->build(hp, input);

    hp->insert(hp, 20);

    hp->remove();


    return 0;
}

