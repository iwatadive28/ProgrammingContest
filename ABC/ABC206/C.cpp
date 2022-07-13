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
ll comb(int n,int m){
    ll C = 1;
    ll c = 1;
    rep(i,m) C*=(n-i);
    rep(i,m) c*=(m-i);
    
    C/=c;
    return C;
}

int main(){
    int N;
    
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    map<int,int> mp;
    rep(i,N){
        if (mp.find(A[i]) == mp.end()){
            mp[A[i]] = 1;
        }else{
            mp[A[i]]++;
        }        
    }

    ll ans = comb(N,2);
    for (auto itr = mp.begin();itr != mp.end() ; itr++ ){
        if (itr->second > 1){
            ans -= comb(itr->second,2);
        }
    }


    cout << ans << endl;
    
}