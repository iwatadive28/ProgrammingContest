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
    ll K,N;
    cin >> K >> N;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];

    ll ans = INF;
    rep(i,N){
        if(i==0) chmin(ans,A[N-1]-A[i]);
        else     chmin(ans,(K-A[i])+A[i-1]);
    }
    cout << ans << endl;
}