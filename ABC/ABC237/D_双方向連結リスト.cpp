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

// 双方向連結リストの各ノードを表す構造体
struct Node{
    Node *next,*prev;
    string name;

    Node(string name_ = "") : 
    prev(NULL), next(NULL), name(name_){}
};

// 番兵を表すノードをグローバル領域においておく
Node* nil;

// 初期化
void init(){
    nil = new Node();
    nil->prev = nil;
    nil->next = nil;
}

// 連結リストの出力
void printList(){
    Node* cur = nil->next; // 先頭から出発
    for (;cur!=nil;cur=cur->next){
        cout << cur->name << " " ;
    }
    cout << endl;
}
// ノードpの直後にノードvを挿入する
// ノードpのデフォルト引数をnilとしておく
// そのため、insert(v)を呼び出す操作は、リストの先頭への挿入を表す
// ノードvをノードpのLRのどちらかに挿入する.デフォルトR 
void insert(Node* v, Node* p = nil, char c = 'R'){
    if (c=='R'){
        v->next = p->next;
        p->next->prev = v;
        p->next = v;
        v->prev = p; 
    }else if (c=='L'){
        v->prev = p->prev;
        p->prev->next = v;
        v->next = p;
        p->prev = v;
    }else cout << "Invalid Input Char." << endl;
}

int main(){
    
    int N;
    string S;
    cin >> N;
    cin >> S;

    // 初期化
    init();
    // ノードを作成する
    Node* node = new Node("0");
    insert(node);
    Node* prevnode = node;

    rep(i,N){
        Node* node = new Node(to_string(i+1));
        if (S[i] == 'L'){
            insert(node,prevnode,'L');
        }else{
            insert(node,prevnode);
        }
        prevnode = node;
        // printList();
    }
    
    printList();
}