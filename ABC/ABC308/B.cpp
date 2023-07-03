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
    int N,M;
    cin >> N >> M;
    vector<string> C(N);
    rep(i,N) cin >> C[i];
    
    
    vector<string> D(M);
    rep(i,M) cin >> D[i];
    vector<int> P(M+1);
    rep(i,M+1) cin >> P[i];

    map<string,int> mp;
    rep(i,M) mp[D[i]]=P[i+1];
    
    int ans = 0;
    rep(i,N){
        if (mp.find(C[i]) == mp.end()) ans += P[0];
        else ans += mp[C[i]];
    }
    cout << ans << endl;
}