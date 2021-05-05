/*

Created on : 2020-10-02 21:42:31
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

// void solve(){

// }
void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
class MaxHeap{
    vector<int> arr;
    MaxHeap(){

    }
    public:
    void push(int x){
        arr.push_back(x);
        int child = arr.size()-1;
        int parent = (child-1)/2;
        while(arr[child] > arr[parent]){
            swap(&arr[child], &arr[parent]);
            child = parent;
            parent = (parent-1)/2;
        }
        cout<<"pushed "<<x<<" successfully\n";
    }

    void remove_by_value(int x){
        int i;
        for(i=0; i<arr.size(); i++){
            if(arr[i] == x) break;
        }
        if(i == arr.size()){
            cout<<x<<" not found:(\n";
            return;
        } 
        swap(&arr[i],&arr[arr.size()-1]);
        cout<<x<<" removed successfully:)\n";
        arr.erase(arr.end());
        heapify();
    }
    int peek(){
        return arr[0];
    }

    void pop(){
        swap(&arr[0], &arr[arr.size()-1]);
        arr.erase(arr.end());
        heapify();
    }

    void heapify(){
        int root = 0;
        while(true){
            if(root*2+1 > arr.size()) break;
            int next = (arr[root*2+1] > arr[root*2+2])? root*2+1: root*2+2;
            swap(&arr[root], &arr[next]);
            root = next;
        }
        cout<<"heapify successful!!\n";
    }
};

int main(){

    return 0;
}