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
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];

    bool ans = true;
    rep(i,N){
        if(A[i]%2==1) continue;
        if(!(A[i]%3==0 || A[i]%5==0)) ans = false;
    }

    cout << (ans?"APPROVED":"DENIED") << endl;
}
