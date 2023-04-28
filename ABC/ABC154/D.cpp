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
    ll N,K;
    cin >> N >> K;
    vector<ll> p(N,0);
    rep(i,N) cin >> p[i];
    
    vector<ll> sum;
    sum.push_back(0);
    rep(i,200000) sum.push_back(sum[i]+i+1);
    
    vector<double> E(N);
    rep(i,N) E[i] = (double)sum[p[i]]/(double)p[i];
    
    double cur = 0;
    rep(i,K) cur+=E[i];
    double ans = cur;    
    rep(i,N-K){
        cur -= E[i];
        cur += E[i+K];
        chmax(ans,cur);
    }
    printf("%.6f\n",ans);
}