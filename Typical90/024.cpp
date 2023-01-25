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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    ll N,K;
    cin >> N >> K;
    vector<int> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    ll sum = 0;
    rep(i,N) sum += abs(A[i]-B[i]);
    // cout << sum << endl;
    bool ans = false;
    if(K-sum>=0&&(K-sum)%2==0) ans = true;
    
    cout << (ans?"Yes":"No") << endl;
}