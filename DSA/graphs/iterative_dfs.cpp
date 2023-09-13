#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;


class Stack{
    private:
        vector<char> stk;
        int size = 0;
        int rear = -1;
        int front = 0;

    public:
        Stack() {
            stk = {};
            size = 0;
            rear = -1;
            front = 0;
        }

        void push(char node) {
            stk.push_back(node);
            size++;
            rear++;
        }

        char pop() {
            if(size == 0) {
                return ' ';
            }

            char output = stk[rear];
            stk.pop_back();
            rear--;
            size--;
            return output;
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

vector<char> dfs(map<char, vector<char>> adj_list) {
    vector<char> ouput_vector;
    map<char, bool> visited;
    Stack stk = Stack();

    stk.push(adj_list.begin()->first);
    visited[adj_list.begin()->first] = true;

    while (!stk.is_empty()) {

        char node = stk.pop();
        ouput_vector.push_back(node);

        vector<char> neighbours = adj_list[node];

        for(int i = 0; i < neighbours.size(); i++) {
            if(visited.find(neighbours[i]) == visited.end()) {
                visited[neighbours[i]] = true;
                stk.push(neighbours[i]);
            }

        }
    
    }


    return ouput_vector;
}


int main(void) {

    map<char, vector<char>> adjacency_list;
    adjacency_list['a'] = {'b' , 'f'};
    adjacency_list['b'] = {'a' , 'f', 'c'};
    adjacency_list['c'] = {'b' , 'e', 'd'};
    adjacency_list['d'] = {'c' , 'e'};
    adjacency_list['e'] = {'d' , 'c', 'f'};
    adjacency_list['f'] = {'a', 'b' , 'e'};

    vector<char> result = dfs(adjacency_list);

    print_vector(result);


    return 0;
}


