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
    vector<ll> B(N-1,0),A(N);
    rep(i,N-1) cin >> B[i];

    A[0] = B[0];
    rep(i,N-1){
        A[i+1] = B[i];
        if(A[i]>B[i]) A[i] = B[i];
    }
    ll ans = 0;
    rep(i,N) ans += A[i];
    cout << ans << endl;
}