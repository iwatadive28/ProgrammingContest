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
const ll INF  = 1LL << 60;  //無限大
const int inf = 1000000010;
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W));
    rep(i,H) rep(j,W) cin >> A[i][j];
    
    vector<vector<vector<int>>> dp(H,vector<vector<int>>(2,vector<int>(2,inf)));
    dp[0][0][0] = 0;
	dp[0][0][1] = 1;
    for(int i=1;i<H;++i){
        rep(j,2){
            rep(k,2){
                rep(l,2){
                    vector<int> x(W,-1);
                    if(i!=1) x = A[i-2];
                    // j=1の時は反転させる. ｉ±1の場合について調べる
                    if(j) rep(m,W) x[m] = 1-x[m];
                    
                    vector<int> y=A[i-1];
                    if(k) rep(m,W) y[m] = 1-y[m];

                    vector<int> z = A[i];
                    if(l) rep(m,W) z[m] = 1-z[m];

                    bool ok = true;
                    rep(m,W){
                        if(x[m]!=y[m] && y[m]!=z[m] && // 上下
                           (m==0  ||y[m]!=y[m-1])   && // 左
                           (m==W-1||y[m]!=y[m+1])){    // 右
                                ok = false;
                            }
                    }
                    if(i==H-1){
                        rep(m,W) {
                            if(z[m]!=y[m] &&              // 上下
                               (m==0   ||z[m]!=z[m-1]) && // 左
                               (m==W-1 ||z[m]!=z[m+1])){  // 右
                                  ok = false;
                               }
                        }
                    }
                    if(ok) chmin(dp[i][k][l],dp[i-1][j][k]+(int)l);
                    //*/
                }
            }
        }
    }

    int ans = inf;
    rep(j,2) rep(k,2) chmin(ans,dp[H-1][j][k]);
    if(ans==inf) ans = -1;
    cout << ans<< endl;
}
