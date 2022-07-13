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
    int N,X;
    cin >> N >> X;
    vector<int> a(N),b(N);
    rep(i,N) cin >> a[i] >> b[i];
    
    // DP
    vector<vector<bool>> dp(N+1,vector<bool>(X+1,false));
    // 初期化
    dp[0][0] = true;

    // 配るDP
    rep(i,N){
        rep(j,X){
            if(!dp[i][j]) continue;
            // ai
            if(j+a[i]<=X){
                dp[i+1][j+a[i]] = true;
            }
            if(j+b[i]<=X){
                dp[i+1][j+b[i]] = true;
            }            
        }
    }

    cout << (dp[N][X]?"Yes":"No") << endl;
}