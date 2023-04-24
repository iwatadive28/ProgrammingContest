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
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    map<ll,ll> mp;
    rep(i,N){
        cin >> A[i];
        mp[A[i]]++;
    }
    ll sum = 0;
    for (auto itr = mp.begin();itr != mp.end();itr++){
        ll n = itr->second;
        sum += n*(n-1)/2;
    }
    vector<ll> ans;
    rep(k,N){
        ll n = mp[A[k]];
        ans.push_back(sum-(n-1));
    }
    for(auto a:ans) cout << a << endl;
}