#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;



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
            adj_list[input[i][0]].push_back(input[i][1]);
            adj_list[input[i][1]].push_back(input[i][0]);
        }

    }

    print_adj_list(adj_list);

    return adj_list;
}


void dfs(map<int, vector<int>> &adj_list, int node, map<int, bool> &visited) {
    visited[node] = true;
    vector<int> neighbours = adj_list[node];

    for(int i = 0; i < neighbours.size(); i++) {
        if(visited.find(neighbours[i]) == visited.end()) {
            dfs(adj_list, neighbours[i], visited);
        }
    }
}
int components(map<int, vector<int>> &adj_list, int n) {

        int count = 0;
    map<int, bool> visited;


    
    for(int i = 0; i < n; i++) {
        if(visited.find(i) == visited.end()) {
            count++;
            dfs(adj_list, i, visited);
        }
    }

    return count;
}




int main(void) {

    int n = 5;
    vector<vector<int>> input = {{0, 1}, {3, 1}, {1, 2}, {4}};

    map<int, vector<int>> adj_list = build(input, n);
    int count = 0;
    map<int, bool> visited;

    int result = components(adj_list, n);
    cout << result << endl;


    return 0;
}

