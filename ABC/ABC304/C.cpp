#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll N,D;
    cin >> N >> D;
    vector<ll> X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];


    vector<vector<ll>> dist(N,vector<ll>(N,INF));
    rep(i,N-1){
        for(int j=i;j<N;j++){
            dist[i][j] = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
            dist[j][i] = dist[i][j];
            // cout << dist[j][i] << " ";
        }
        // cout << endl;
    }

    vector<bool> ans(N,false);
    queue<ll> que;
    que.push(0);
    ans[0] = true;
        
    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        ll v = que.front(); // queから先頭頂点を取り出す
        que.pop();
        
        // vから辿れる頂点をすべて調べる
        for(ll i=0;i<N;i++){
            if(ans[i]) continue;
            // cout << v  << "->" << i << ":";
            // cout << dist[v][i] << " " << D*D << endl;
            if(dist[v][i]<=(D*D)){ // ユークリッド距離以内
                que.push(i); // queに挿入
                ans[i] = true;
            }
        }
    }

    rep(i,N){
        cout << (ans[i]?"Yes":"No") << endl;
    }
    
}
