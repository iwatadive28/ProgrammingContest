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

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];

    vector<ll> A(N),B(N),C(N);
    
    int k = 0;
    // Cを作成
    rep(i,N){
        rep(j,y[i]){
            C[k] = x[i];
            ++k;
        }
    }
    
    // cout << k << endl;
    
    rep(i,M){
       cout << C[i] << endl;
    }
    return 0;
    
}