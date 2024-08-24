#include<iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;



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



vector<char> dfs(map<char, vector<char>> &adj_list, char vertex, vector<char> &ouput_vector, map<char, bool> &visited) {
    ouput_vector.push_back(vertex);
    visited[vertex] = true;
    vector<char> neighbours = adj_list[vertex];
    for(int i = 0; i < neighbours.size(); i++) {
        cout << neighbours[i] << endl;
        if(visited.find(neighbours[i]) == visited.end()) {
            dfs(adj_list, neighbours[i], ouput_vector, visited);
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

    map<char, bool> visited;
    vector<char> output;

    vector<char> result = dfs(adjacency_list, 'a', output, visited);
    print_vector(result);

    return 0;

}
