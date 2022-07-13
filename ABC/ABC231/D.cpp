#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//
// Union-Find木
// https://qiita.com/xryuseix/items/eb247016ea04a549c720
class UnionFind {
public:
    // 親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> Parent;

    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }

    // Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }

    // 自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];//親をとってきたい]
    }

    // AとBをくっ付ける
    bool connect(int A, int B) {
        // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }

        // 大きい方(A)に小さいほう(B)をくっ付ける
        // 大小が逆だったらひっくり返す
        if (size(A) < size(B)) {
            swap(A, B);
        }

        // Aのサイズを更新する
        Parent[A] += Parent[B];
        // Bの親をAに変更する
        Parent[B] = A;

        return true;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    
    UnionFind uni(n);
    bool hasLoop = false;
    bool ans = true;
    
    Graph G(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        
        G[a].push_back(b);
        G[b].push_back(a);
        if ( (G[a].size()>2) | (G[b].size()>2) ) {
            ans = false;
            break;
        }

        if(uni.root(a) == uni.root(b)) {
            hasLoop = true;
        }
        uni.connect(a, b);
    }
    
    if(hasLoop) ans = false;

    cout << (ans?"Yes":"No") << endl;
    
}