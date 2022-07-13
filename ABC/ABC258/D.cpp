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
    ll N,X;
    cin >> N >> X;
    vector<ll> A(N),B(N),S(N);
    rep(i,N) cin >> A[i] >> B[i];
    
    S[0] = A[0]+B[0];
    for(ll i=1;i<N;++i) S[i] = S[i-1] + A[i]+B[i];
    
    ull ans = INF;
    rep(i,N){
        ull tm = 0;
        tm += S[i];
        tm += B[i]*(X-(i+1));
        ans = min(tm,ans);
    }

    cout << ans << endl;
}
