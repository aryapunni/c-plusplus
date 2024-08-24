#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;


class Stack{
    private:
        vector<int> stk;
        int size;
        int rear;
        int front;

    public:
        Stack() {
            stk = {};
            size = 0;
            rear = -1;
            front  = 0;
        }

        void push(int node) {
            stk.push_back(node);
            size++;
            rear++;
        }

        int pop() {
            if(size == 0) {
                return -1;
            }
            int result = stk[rear];
            rear--;
            size--;
            stk.pop_back();
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

        void print() {

            if(size == 0) {
                cout << "[]" << endl;
                return;
            }

            cout << "[";
            for(int i = front; i <= rear; i++) {
                cout << stk[i] << ", ";
            }

            cout << "]" << endl;
        }

};

void print_vector(vector<int> input) {

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


void print_adj_list(map<int, vector<int>> input) {

    cout << "Adjacency list: ";

    map<int, vector<int>>::iterator itr;
    for(itr = input.begin(); itr != input.end(); itr++) {
        cout << itr->first << ": [";

        for(int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i] << ", ";
        }

        cout << "]  , ";
    }
    cout << endl;

}


map<int, vector<int>> build(vector<vector<int>> input, int n) {

    map<int, vector<int>> adj_list;

    for(int i = 0; i < n; i++) {
        adj_list[i] = {};
    }

    for(int i = 0; i < input.size(); i++) {
        // print_vector(input[i]);
        if(input[i].size() > 0) {
            adj_list[input[i][1]].push_back(input[i][0]);
        }

    }

    print_adj_list(adj_list);

    return adj_list;
}

vector<int> build_indegree(vector<vector<int>> edges, int n) {
    vector<int> indegree(n, 0);
    for(int i = 0; i < edges.size(); i++) {
        indegree[edges[i][0]]++;
    }
    return indegree;
}

bool topological_sort(map<int, vector<int>> adj_list, vector<int> indegree) {
    Stack stk = Stack();
    int count = 0;
    vector<int> toposort_list;

    for(int  i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) {
            stk.push(i);
            toposort_list.push_back(i);
        }
    }

    while(!stk.is_empty()) {

        int node = stk.pop();
        count++;
        vector<int> neighbours = adj_list[node];

        for(int i = 0; i < neighbours.size(); i++) {

            indegree[neighbours[i]]--;
            

            if(indegree[neighbours[i]] == 0) {
                stk.push(neighbours[i]);
                toposort_list.push_back(neighbours[i]);
            }

            cout << "stack: ";
            stk.print();
            cout << "indegree List: ";
            print_vector(indegree);
            cout << "toposort List: ";
            print_vector(toposort_list);

        }

    }

    if(count != indegree.size()) {
        return false;
    }



    return true;
}



int main(void) {
    vector<vector<int>> acyclic_edges = {{4,1}, {2, 1}, {2, 3}, {5, 3}, {0, 3}, {5, 0}, {5, 4}};
    vector<int> indegree = build_indegree(acyclic_edges, 6);
    map<int, vector<int>> adj_list = build(acyclic_edges, 6);

    bool status = topological_sort(adj_list, indegree);
    cout << "status: " << status << endl;


    cout << "-----------------------------cyclic garph------------------------------------" << endl;
    vector<vector<int>> cyclic_edges = {{1, 0}, {1, 3}, {2, 1}, {3, 2},};
    indegree = build_indegree(cyclic_edges, 4);
    print_vector(indegree);
    adj_list = build(cyclic_edges, 4);

    status = topological_sort(adj_list, indegree);
    cout << "status - cyclic: " << status << endl;
    return 0;
}