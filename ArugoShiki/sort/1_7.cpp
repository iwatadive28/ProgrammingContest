#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
/*
*/
//
void output(vector<ll> a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
    return;
}

// ヒープソート
int main(){
    // INPUT
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    // 1. 
    ll x = N/2;
    
    // 2.
    while(x>=0){

    }

    // 3.
    --x;
    
    // 4. 配列 B の値を出力する。
    output(a);

    return 0;
}