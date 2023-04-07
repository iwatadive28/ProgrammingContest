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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N,0),B(M,0);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    vector<pair<ll,ll>> C;
    rep(i,N) C.push_back({A[i],0});
    rep(i,M) C.push_back({B[i],1});
    sort(C.begin(),C.end());
    
    vector<ll> c(N+M,0);
    rep(i,N+M) c[i] = C[i].first;
    c = zahyo(c);
    rep(i,N+M) if(C[i].second==0) cout << c[i]+1 << " ";
    cout << endl; 
    rep(i,N+M) if(C[i].second==1) cout << c[i]+1 << " ";
    cout << endl; 
}