/*

Created on : 2021-05-02 11:32:08 
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
    The TRIE data structure should be used for efficient pattern matching. Each node consists of 26 children, a boolean end of word and optionally an integer to count how many words end at the particular node.
*/

typedef struct TrieNode* TNodePtr;

typedef struct TrieNode{
    TNodePtr children[26];
    bool EOW;
    int num_words;
}TrieNode;

TNodePtr getNode(void){
    TNodePtr ptr = (TNodePtr)malloc(sizeof(TrieNode));
    ptr->EOW = false;
    ptr->num_words = 0;
    for(int i=0; i<26; i++){
        ptr->children[i] = nullptr;
    } 
    return ptr;
}

void insert(TNodePtr root, string s){
    TNodePtr ptr = root;
    for(char x: s){
        int index = x-'a';
        if(!ptr->children[index]){
            ptr->children[index] = getNode();
        }
        ptr = ptr->children[index];
    }
    ptr->EOW = true;
    ptr->num_words++;
}

bool search(TNodePtr root, string key){
    TNodePtr ptr = root;
    for(char x: key){
        if(ptr->children[x-'a'] == nullptr) return false;

        ptr = ptr->children[x-'a'];
    }
    return true;
}

bool match(TNodePtr root, string key){
    TNodePtr ptr = root;
    for(auto x: key){
        int index = x-'a';
        if(ptr->children[index] == nullptr){
            return false;
        }
        ptr = ptr->children[index];
    }
    return ptr!=NULL && ptr->EOW;
}

int main(){

    return 0;
}