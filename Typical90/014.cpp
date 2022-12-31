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
    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    // ソート
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    // 貪欲法
    ll ans = 0;
    rep(i,N){
        ans += abs(A[i]-B[i]);
    }
    cout << ans << endl;

}   