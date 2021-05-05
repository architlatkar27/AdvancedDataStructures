/*

Created on : 2020-09-26 22:22:11
author name : archit nitin latkar

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
    Description - Implementation of Integer-based Priority Queue using Linked-List (vector). 
    Used this to implement Dijkstra's Algorithm
*/

// void solve(){

// }
class Edge; 
class Node;
class PriorityQueue;

class Node{
    public:
    int id;
    vector<Edge> edges;
    bool visited;
    int dist;
    Node* prev;
    Node(){}
    Node(int id){
        this->id = id;
        visited = false;
        dist = INF;
    }

    void addEdge(Edge e){
        edges.push_back(e);
    }

    void setDistance(Node* p, int d){
        if(dist > d){
            dist = d;
            prev = p;
        }
    }

    bool operator<(const Node x){
        if(this->dist > x.dist) return true;
        return false;
    }
};

class Edge{
    private:
    Node start;
    Node end;
    int weight;
    public:
    Edge(Node start, Node end, int weight){
        this->start = start;
        this->end = end;
    }
};

void swap(Node* x, Node* y){
    Node temp = *x;
    *x = *y;
    *y = temp;
}
class PriorityQueue{
    public:
    vector<Node> pqueue;
    PriorityQueue(Node s){
        pqueue.push_back(s);
    }

    void push(Node x){
        pqueue.push_back(x);
        int child = pqueue.size()-1;
        int parent = (child-1)/2;
        while(pqueue[child] < pqueue[parent]){
            swap(&pqueue[child], &pqueue[parent]);
            child = parent;
            parent = (parent-1)/2;
            if(child == 0) break; 
        }
    }

    void remove_by_value(Node s){
        int i;
        for(i=0; i<pqueue.size(); i++){
            if(s.id == pqueue[i].id) break;
        }
        swap(&pqueue[i], &pqueue[pqueue.size()-1]);
        pqueue.erase(pqueue.end());
        reorder();
    }

    Node peek(){
        return pqueue[0];
    }

    void pop(){
        swap(&pqueue[0], &pqueue[pqueue.size()-1]);
        pqueue.erase(pqueue.end());
        reorder();
    }

    void reorder(){
        int root = 0;
        while(true){
            if(root*2+1 > pqueue.size()) break;
            int next = (pqueue[2*root+1] < pqueue[2*root+2])? root*2+1: root*2+2;
            swap(&pqueue[root], &pqueue[next]);
            root = next;
        }
    }
};

void algorithm(vector<Node>& nodes, int n, int source){
    nodes[source].dist = 0;
    nodes[source].prev = NULL;
    PriorityQueue pq(nodes[source]);
    while(pq.pqueue.size() > 0){
        Node curr = pq.peek();
        curr.visited = true;
        
    }
}

int main(){
    cout<<"Welcome to my implementation of Dijkstra's algorithm :)\n";
    cout<<"-------------------------------------------------------\n";
    int n;
    cout<<"How many edges does your graph have?\n";
    cin>>n;
    cout<<"Readying graph nodes...\n";
    vector<Node> nodes;
    for(int i=0;i<n;i++){
        Node n(i);
        nodes.push_back(n);
    }
    cout<<"How many edges does your graph have?\n";
    int e;
    cin>>e;
    cout<<"OK now input each edge in the following manner: vertex1 vertex2 weight\n";
    cout<<"!!!Remember that edges are bidirectional!!!\n";
    for(int i=0;i<n;i++){
        int v1, v2, w;
        cin>>v1>>v2>>w;
        Edge e1(nodes[v1], nodes[v2], w);
        Edge e2(nodes[v2], nodes[v1], w);
        nodes[v1].addEdge(e1);
        nodes[v2].addEdge(e2);
    }
    int source;
    cout<<"From where would you like to start?\n";
    algorithm(nodes,n, source);

    return 0;
}