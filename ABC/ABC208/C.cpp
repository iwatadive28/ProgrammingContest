#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    vector<ll> b = a;
    sort(b.begin(),b.end());

    map<ll,ll> mp; // a[i],num;
    
    // K>=N O(NlogN)
    rep(i,N) mp[b[i]] = K/N;
    K %= N;
    
    // K<Nの時 O(NlogN)
    rep(i,N){
        if (K==0) break;
        mp[b[i]]++;
        K--;        
    }

    rep(i,N) cout << mp[a[i]] << endl;
}