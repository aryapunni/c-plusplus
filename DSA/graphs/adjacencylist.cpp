#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

class Queue{
    private:
        vector<char> q;
        int rear;
        int front;
        int size;

    public:
        Queue() {
            q = {};
            rear = -1;
            front = 0;
            size = 0;
        }

        void enqueue(char node) {
            q.push_back(node);
            rear++;
            size++;
        }

        char dequeue() {
            if(size == 0) {
                return '0';
            }

            char result = q[front];
            front++;
            size--;
            return result;
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

vector<char> bfs(map<char, vector<char>> input) {

    Queue nodes = Queue();
    vector<char> ouput_vector;
    map<char, bool> visited;

    map<char, vector<char>> :: iterator itr;

    nodes.enqueue(input.begin()->first);
    visited[input.begin()->first] = true;


    while(!nodes.is_empty()) {
        char node = nodes.dequeue();
        ouput_vector.push_back(node);

        vector<char> neighbours = input[node];
        for(int i = 0; i < neighbours.size(); i++) {
            if(visited.find(neighbours[i]) == visited.end()) {
                cout << neighbours[i] << endl;
                visited[neighbours[i]] = true;
                nodes.enqueue(neighbours[i]);
            }
        }

    }
    return ouput_vector;


}

void print_vector(vector<char> input) {

    cout << "{";
    if(input.empty()) {

        cout << "}" << endl;
        return;

    }

    for(int i = 0; i < input.size(); i++) {
        cout << input[i] << ", ";
    }

    cout << "}" << endl;
}




int main(void) {

    map<char, vector<char>> adjacency_list;
    adjacency_list['a'] = {'b' , 'f'};
    adjacency_list['b'] = {'a' , 'f', 'c'};
    adjacency_list['c'] = {'b' , 'e', 'd'};
    adjacency_list['d'] = {'c' , 'e'};
    adjacency_list['e'] = {'d' , 'c', 'f'};
    adjacency_list['f'] = {'a', 'b' , 'e'};

    vector<char> result = bfs(adjacency_list);

    print_vector(result);

    return 0;

}
