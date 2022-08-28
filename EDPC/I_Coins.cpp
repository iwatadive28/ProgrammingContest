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
    vector<double> p(N);
    rep(i,N) cin >> p[i];
    
    vector<vector<double>> dp(N+1,vector<double>(N+1,0));
    dp[0][0] = 1;
    // i番目のコインがj枚表になる確率
    for(int i=0;i<N;++i){
        rep(j,i+1){
            // 裏の場合
            dp[i+1][j] += dp[i][j]*(1-p[i]);
            // 表の場合
            dp[i+1][j+1] += dp[i][j]*p[i];
        }
    }

    /*
    rep(i,N+1) {
        rep(j,N+1){
            cout << dp[i][j] << " ";
        } 
        cout << endl;
    }
    */
    
    double ans = 1;
    rep(i,N/2+1) ans -= dp[N][i];
    printf("%.9f\n",ans);
}
