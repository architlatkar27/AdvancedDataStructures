/*

Created on : 2021-06-29 19:56:27
@author    : archit nitin latkar

*/

#include<iostream>
#include<bits/stdc++.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;


/*
Kosaraju's algorithm for finding strongly connected components
1. DFS through the graph and just before returning, push nodes on a stack
2. Reverse the graph
3. Pop node from graph and run dfs with it as source if it is not yet visited. Each run of DFS will return a SCC
*/

stack<int> node_stack;

vector<vector<int>> scc;

void dfs1(vector<vector<int>>& graph, vector<bool>& visited, int s){
    visited[s] = true;
    for(auto x: graph[s]){
        if(!visited[x]){
            dfs1(graph, visited, x);
        }
    }
    node_stack.push(s);
}

void dfs2(vector<vector<int>>& transpose, vector<bool>& visited, int s, vector<int>& curr_scc){
    visited[s] = true;
    for(auto x: transpose[s]){
        if(!visited[x]){
            dfs2(transpose, visited, x, curr_scc);
        }
    }
    curr_scc.push_back(s);
}

int main(){
    cout<<"Kosaraju's algorithm for finding SCC\n====================================\n";
    cout<<"Enter number of nodes: ";
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    vector<vector<int>> transpose(n);
    vector<bool> visited(n, false);
    int e;
    cout<<"How many edges? ";
    cin>>e;
    for(int i=0; i<e; i++){
        int s, d;
        cout<<"Enter source and destination: ";
        cin>>s>>d;
        graph[s].push_back(d);
        transpose[d].push_back(s);
    }
    cout<<"graphs initialized\n\n";

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs1(graph, visited, i);
        }
    }
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    while(!node_stack.empty()){
        int s = node_stack.top();
        node_stack.pop();
        if(!visited[s]){
            vector<int> curr_scc;
            dfs2(transpose, visited, s, curr_scc);
            scc.push_back(curr_scc);
        }
    }

    for(int i=0; i<scc.size(); i++){
        for(int j=0; j<scc[i].size(); j++){
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}