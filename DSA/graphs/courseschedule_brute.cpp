#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

class Queue{
    private:
        vector<int> q;
        int size;
        int rear;
        int front;

    public:
        Queue() {
            q = {};
            size = 0;
            rear = -1;
            front = 0;
        }

        void enqueue(int node) {
            q.push_back(node);
            size++;
            rear++;
        }

        int dequeue() {
            if(size == 0) {
                return -1;
            }
            int result = q[front];
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


void print_visited(map<int, bool> input) {

    map<int, bool> :: iterator itr;

    if(input.empty()) {
        cout << "{}" << endl;
        return;
    }
    cout << "{";

    for(itr = input.begin(); itr != input.end(); itr++) {

        cout << "[" << itr->first << ", " << itr->second << "], ";

    } 
    cout << "}" << endl;

}



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

    map<int, vector<int>>::iterator itr;
    for(itr = input.begin(); itr != input.end(); itr++) {
        cout << itr->first << ": [";

        for(int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i] << ", ";
        }

        cout << "]" << endl;
    }

}


map<int, vector<int>> build(vector<vector<int>> input, int n) {

    map<int, vector<int>> adj_list;

    for(int i = 0; i < n; i++) {
        adj_list[i] = {};
    }

    for(int i = 0; i < input.size(); i++) {
        print_vector(input[i]);
        if(input[i].size() > 1) {
            adj_list[input[i][1]].push_back(input[i][0]);
            // adj_list[input[i][1]].push_back(input[i][0]);
        }

    }

    print_adj_list(adj_list);

    return adj_list;
}

bool bfs(map<int, vector<int>> adj_list, int node, map<int, bool> &visited) {

    Queue q = Queue();
    visited[node] = true;
    q.enqueue(node);


    while(!q.is_empty()) {
        int dq = q.dequeue();
        vector<int> neighbours = adj_list[dq];
        
        for(int i = 0; i < neighbours.size(); i++) {
            if(visited.find(neighbours[i]) == visited.end()) {
                q.enqueue(neighbours[i]);
                visited[neighbours[i]] = true;
            }
            else {
                return false;
            }
        }
    
    }
    return true;
}

bool course_scheduler(map<int, vector<int>> adj_list, int n) {

    map<int, bool> visited;

    for(int i = 0; i < n; i++) {
        cout << "visited nodes after " << i << " cycles" << endl;
        print_visited(visited);

        if(visited.find(i) == visited.end()) {

            bool status = bfs(adj_list, i, visited);

            if(status == false) {
                return false;
            }

        }


        
    }
    return true;
}


int main(void) {

    vector<vector<int>> edges = {{0}, {1}, {3, 2}, {4, 3}, {5, 4}}; //, {2, 5}};

    int n = edges.size();
    map<int, vector<int>> adj_list = build(edges, n);

    bool status = course_scheduler(adj_list, 6);

    cout << "status: " << status << endl;


    return 0;

}