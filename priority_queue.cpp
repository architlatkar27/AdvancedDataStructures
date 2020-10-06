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
class Edge ; 
class Node;
class Node{
    public:
    int id;
    vector<Edge> edges;
    bool visited;
    int dist;
    Node* prev;
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
    Node* start;
    Node* end;
    int weight;
    Edge(Node* start, Node* end, int weight){
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
        
    }

    Node peek(){

    }

    void pop(){

    }
};

int main(){
    
    return 0;
}