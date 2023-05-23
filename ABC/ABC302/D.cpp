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
    ll N,M,D;
    cin >> N >> M >> D;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    vector<ll> B(M,0);
    rep(i,M) cin >> B[i];

    sort(A.begin(),A.end(),greater<ll>()); // 
    sort(B.begin(),B.end()); // ,greater<ll>()

    ll ans = -1;
    for(auto a:A){
        // a+Dより大きい値のうち、最も小さい値のインデックス -1
        ll b = upper_bound(B.begin(),B.end(),a+D)-B.begin()-1;
        if (b<0||abs(B[b]-a)>D) continue; 
        if(chmax(ans,B[b]+a))  break;
    }
    cout << ans << endl;
}