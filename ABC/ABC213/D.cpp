#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
Graph G;
vector<int> ans;

void dfs(int crr,int pre){
    ans.push_back(crr);
    for(int nxt:G[crr]){
        if(nxt!=pre){
            dfs(nxt,crr); // 深さ優先
            ans.push_back(crr);//帰ってきたときの記録 
        }
    }
}

int main(){
    int N;
    cin >> N;

    G.resize(N+1);
    rep(i,N-1){
        int A,B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);// 無向グラフの場合、逆の辺も張る
    }
    rep(i,N){
        sort(G[i+1].begin(), G[i+1].end());
    }

    dfs(1,-1);
    
    for(int a:ans) cout << a << " ";
    cout << endl;
}