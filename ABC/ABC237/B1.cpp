#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

struct Node {
    Node* next;
    string name;
    Node(string name_ = "") : next(NULL),name(name_){}
}

Node* nil;

// 初期化
void init(){
    nil  = new Node();
    nil->next = nil; //
}

// 連結リスト出力
void printList(){
    Node* cur = nil->next;
    for (;cur!=nil;cur=cur->next){
        cout << cur->name 
    }
    cout endl;
}



int main(){
    int N;
    string S;

   
    cout << pairs[i].second + 1 << endl;
    
}