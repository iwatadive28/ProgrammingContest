#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> C(H,vector<char>(W));    
    rep(i,H) rep(j,W) cin >> C[i][j];
    // calculation

    vector<vector<int>> dp(H,vector<int>(W,0));
    dp[0][0] = 1;
    
    // O(HW)
    rep(i,H){
        rep(j,W){
            if (dp[i][j]==0 | C[i][j]=='#') continue;
            // 下
            if (i+1 < H){
                if (C[i+1][j] == '.') dp[i+1][j] = max(dp[i][j]+1,dp[i+1][j]);
            }

            // 右
            if (j+1 < W){
                if (C[i][j+1] == '.' ) dp[i][j+1] = max(dp[i][j]+1,dp[i][j+1]);
            }
            
        }
    }
    
    int ans=0;
    rep(i,H){
        rep(j,W) {
            if (ans < dp[i][j]) ans = dp[i][j];
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    } 
    cout << ans << endl;
}