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
// 周期性を使って解く
int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i],A[i]--;

    deque<ll> a;
    vector<ll> seen(N,-1);
    ll cur = 0;
    ll ii = 0;
    while(true){
        if(seen[cur]!=-1){
            break;
        }else{
            seen[cur] = ii; // ii番目に訪れた
            a.push_back(cur);
            cur = A[cur];
            ii++;
        }
    }
    
    vector<int> a0,roop;
    ll b = seen[cur];

    rep(i,a.size()){
        if(i<b) a0.push_back(a[i]);
        else roop.push_back(a[i]);
    }

    ll n = a.size()-b;
    ll ans;
    
    // cout << n << "," << b << "," << K << endl;
    if (K<b) ans = a0[K];
    else ans = roop[(K-b)%n];

    cout << ans+1 << endl;    
    
}
