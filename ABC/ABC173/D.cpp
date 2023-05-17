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
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end(),greater<ll>()); 
    

    ll ans = A[0];
    for (ll i=0; i<N-2; i++){
        ans += A[i/2+1];
    }
    cout << ans << endl;
}