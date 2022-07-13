#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    vector<vector<bool>> dp(N,vector<bool>(2,false));
    dp[0][0] = dp[0][1] = true;
       
    rep(i,N-1){
        if(dp[i][0]){
            if(abs(A[i]-A[i+1])<=K) dp[i+1][0] = true;
            if(abs(A[i]-B[i+1])<=K) dp[i+1][1] = true;
        }
        if(dp[i][1]){
            if(abs(B[i]-A[i+1])<=K) dp[i+1][0] = true;
            if(abs(B[i]-B[i+1])<=K) dp[i+1][1] = true;
        }
    }
    bool ans = false;    
    rep(i,2) if(dp[N-1][i]) ans = true;    
    cout << (ans?"Yes":"No") << endl;
    
}