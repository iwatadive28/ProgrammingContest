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
//
int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    ll sum = 0;
    rep(i,N){
        sum += A[i];
        sum %= MOD;
    }

    ll ans = 0;
    rep(i,N){
        sum -= A[i];
        if(sum<0) sum+=MOD;
        ans += A[i]*sum;
        ans %= MOD;
    }

    cout << ans << endl;
}
