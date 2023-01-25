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
    int N,X;
    cin >> N >> X;
    vector<int> A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];
    
    vector<vector<bool>> dp(N+1,vector<bool>(X+1,false));
    dp[0][0] = true;
    
    rep(i,N){
        rep(j,X+1){ // j円のとき
            rep(k,B[i]+1){ // A[i]硬貨をk枚使った場合
                if(j>=A[i]*k){
                    if(dp[i][j-A[i]*k]) dp[i+1][j] = true;
                }                
            }
        }
    }

    cout << (dp[N][X]?"Yes":"No") << endl;
}
