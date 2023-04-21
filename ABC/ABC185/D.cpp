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
    A.push_back(N+1);
    A.push_back(0);
    sort(A.begin(),A.end());
    vector<ll> B;
    ll k = INF;
    rep(i,A.size()-1){
        if(A[i+1]==A[i]+1) continue;
        B.push_back(A[i+1]-A[i]-1);
        chmin(k,A[i+1]-A[i]-1);
    }

    ll ans = 0;
    rep(i,B.size()){
        ans+=B[i]/k;
        if(B[i]%k!=0)ans++;
    }
    cout << ans << endl;   
    
}