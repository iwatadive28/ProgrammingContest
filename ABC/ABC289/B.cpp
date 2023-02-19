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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M,0);
    rep(i,M) cin >> A[i];

    vector<bool> re(N+1,false);
    rep(i,M) re[A[i]] = true;

    vector<ll> ans;
    for(ll i=1,j=1;i<=N;i = ++j){
        while(re[j]) j++;
        for(ll k=j;k>=i;k--) ans.push_back(k);
    }

    rep(i,N) cout << ans[i] << endl;
}