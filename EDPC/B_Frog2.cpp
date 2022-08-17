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
    int N,K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i,N) cin >> h[i];
    
    // 初期化
    vector<ll> dp(N,INF);
    dp[0] = 0;
    
    // 配るDP
    rep(i,N){
        for(int j=1;j<=K;++j){
            if(i+j>=N) continue;            
            chmin(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
        }        
    }

    /*
    rep(i,N+1){
        cout << dp[i][j] << " ";
    }
    cout << endl;
    */
    
    cout << dp[N-1] << endl;
}
