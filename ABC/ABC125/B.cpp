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
    int N;
    cin >> N;
    vector<int> V(N),C(N);
    rep(i,N) cin >> V[i];
    rep(i,N) cin >> C[i];
    vector<int> B(N);
    rep(i,N) B[i] = V[i]-C[i];
    
    sort(B.begin(),B.end(),greater<int>()); // ,greater<ll>()
    
    ll ans = 0;
    rep(i,N){
        if(B[i]<=0) break;
        ans += B[i];
    }
    cout << ans << endl;
}