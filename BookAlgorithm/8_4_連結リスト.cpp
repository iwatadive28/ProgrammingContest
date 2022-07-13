#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

// 連結リストの各ノードを表す構造体
struct Node{
    Node* next;
    string name;

    Node(string name_ = "") : next(NULL), name(name_){}
};

// 番兵を表すノードをグローバル領域においておく
Node* nil;

// 初期化
void init(){
    nil = new Node();
    nil->next = nil;
}

// 連結リストの出力
void printList(){
    Node* cur = nil->next; // 先頭から出発
    for (;cur!=nil;cur=cur->next){
        cout << cur->name << "->" ;
    }
    cout << endl;
}

// ノードpの直後にノードvを挿入する
// ノードpのデフォルト引数をnilとしておく
// そのため、insert(v)を呼び出す操作は、リストの先頭への挿入を表す
void insert(Node* v, Node* p = nil){
    v->next = p->next;
    p->next = v;
}

int main(){ 
    // 初期化
    init();
    // 作りたいノードの名前一覧
    // 最後のノード「山本」から挿入することにする
    int N;
    cin >> N;
    vector<string> names(N);
    
    rep(i,N) cin >> names[i];

    // 各ノードを生成して、連結リストの先頭に挿入していく
    rep(i,N){
        // ノードを作成する
        Node* node = new Node(names[i]);
        // 作成したノードを連結リストの先頭に挿入する
        insert(node);
        // 各ステップの連結リストの様子を出力する
        cout << "step "<< i << ":";
        printList();
    }

    return 0;
}