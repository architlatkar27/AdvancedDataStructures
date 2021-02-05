/*

Created on : 2021-01-29 21:17:38
@author    : archit nitin latkar

Topological sort in Directed Acyclic graph
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

vii graph;
vi visited;
vi onstack;
vi order;

void dfs(int s){
    visited[s] = 1;
    onstack[s] = 1;
    for(int i = 0; i<graph[s].size(); i++){
        if(onstack[graph[s][i]]){
            cout<<"Cycle detected\n";
            exit(0);
        }
        if(visited[graph[s][i]]) continue;
        dfs(graph[s][i]);
    }
    order.insert(order.begin(), s);
    onstack[s] = 0;
}

int main(){
    int n;
    cout<<"Enter the number of nodes in graph\n";
    cin>>n;
    graph.resize(n);
    visited.resize(n);
    onstack.resize(n);
    
    for(int i=0; i<n; i++){
        visited[i] = 0;
        onstack[i] = 0;
    }

    int e;
    cout<<"Enter number of edges\n";
    cin>>e;
    cout<<"Enter edges - source --> destination\n";
    for(int i=0; i<e; i++){
        int s, d;
        cin>>s>>d;
        graph[s].push_back(d);
    }

    for(int i=0; i<n; i++){
        if(visited[i] == 0) dfs(i);
    }

    for(int i=0; i<order.size(); i++){
        cout<<order[i]<<" ";
    }
    cout<<endl;
    return 0;
}