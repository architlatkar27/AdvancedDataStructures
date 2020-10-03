/*

Created on : 2020-10-03 21:57:35
@author    : archit nitin latkar

Fenwick Tree

*/

#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

// void solve(){

// }
class FenwickTree{
    vector<int> tree;
    int length;
    FenwickTree(vector<int> arr){
        tree.push_back(0); // dummy element, our array starts at index 1
        for(int i=0; i<arr.size(); i++){
            tree.push_back(arr[i]);
        }
        length = arr.size();
        for(int i=1;i<= length; i++){
            int x = log2(i & -i)+1;
            int j = x+i;
            if(j < length){
                tree[j] += tree[i];
            }
        }
    }

    int prefix_sum(int index){
        int sum = 0;
        while(index > 0){
            sum += tree[index];
            index -= (int)(log2(index & -index)+1);
        }
        return sum;
    }
    void point_update(int i, int x){
        int diff = tree[i]-x;
        while(i<length){
            tree[i] += diff;
            i += (int)(log2(i & -i)+1);
        }
    }

    int range_sum(int i,int j){
        return prefix_sum(j)-prefix_sum(i-1);
    }
};

int main(){

    return 0;
}