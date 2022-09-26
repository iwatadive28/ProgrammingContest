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
    ull N;
    cin >> N;
    vector<int> a; 
    rep(i,60){
        if(N&(1LL<<i)) a.push_back(i);
    }

    int k = a.size();
    vector<ll> res;
    rep(i,1<<k){
        ll cur = 0;
        rep(j,k){
            if(i&(1<<j)) cur|= 1ll<<a[j];
        }
        res.push_back(cur);
    }

    for(auto &nx:res) cout << nx << endl;
}