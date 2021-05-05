/*

Created on : 2021-03-27 21:40:08
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

Floyd Warshall algorithm for APSP - 
**Use adjancency matrix for respresentation
Intuition - the algorithm runs using dynamic programming in time O(V^3). dp[i][j] indicates 
the shortest path between i and j and next[i][j] indicates the next node to visit on the path 
from i to j. k is the third variable used to track which node is in between i and j.

dp[i][j] is set to mat[i][j]
for k in V:
    for i in V:
        for j in V:
            if dp[i][j] < dp[i][k]+dp[k][j]: update dp[i][j] and next[i][j]
if the graph is known to have negative edges, then run the same loops again. if for any vertex 
a smaller distance is found, replace it with -INF and next value as -1 indicating that the path is 
blocked.

*/
int dp[100][100];
int nextnode[100][100];

void setup(int** m, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = m[i][j];
            if(m[i][j] != INF) nextnode[i][j] = j;
        }
    }
}

void negativeCycles(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][k]+dp[k][j] < dp[i][j]){
                    dp[i][j] = LOW;
                    nextnode[i][j] = -1;
                }
            }
        }
    }
}

void floydWarshall(int** m, int n){
    setup(m, n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][k]+dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k]+dp[k][j];
                    nextnode[i][j] = nextnode[i][k];
                }
            }
        }
    }

    negativeCycles(n);
}

int main(){
    cout<<"Welcome to my implementation of Floyd-Warshall algorithm\n";
    cout<<"---------------------------------------------------------\n";
    int n;
    cout<<"How many nodes in the graph?\n";
    cin>>n;
    int **m;
    m = (int**)calloc(n, sizeof(int*));
    for(int i=0; i<n; i++) m[i] = (int*)calloc(n, sizeof(int)); 
    int e;
    cout<<"How many edges?\n";
    cin>>e;
    vector<vector<int>> edges;
    cout<<"Enter edges in start end weight manner\n";
    for(int i=0; i<e; i++){
        vector<int> x(3);
        cin>>x[0]>>x[1]>>x[2];
        edges.push_back(x);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) m[i][j] = 0;
            else m[i][j] = INF;
        }
    }

    for(int i=0; i<e; i++){
        m[edges[i][0]][edges[i][1]] = edges[i][2];
    }   

    floydWarshall(m, n);

    cout<<"---------Output----------\n";
    cout<<"-------------------------\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"-------------------------\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}