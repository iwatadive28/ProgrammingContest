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

// 座標圧縮
vector<ll> zahyo(vector<ll> X){
    vector<ll> Y = X;
    sort(Y.begin(),Y.end());

    Y.erase(unique(Y.begin(),Y.end()),Y.end());
        
    // 座標圧縮した結果を求める
    vector<ll> res(X.size());
    for (int i = 0; i < X.size(); ++i) {
        res[i] = lower_bound(Y.begin(), Y.end(), X[i]) - Y.begin();
    }
    return res;
}

int main(){
    ll H,W,N;
    cin >> H >> W >> N;

    vector<ll> A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];
    
    vector<ll> C = zahyo(A);
    vector<ll> D = zahyo(B);
    
    rep(i,N) cout << C[i]+1 << " " << D[i]+1 << endl;
}