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
    int N;
    cin >> N;
    vector<int> T(N);
    ll S=0;
    rep(i,N){
        cin >> T[i];
        S += T[i];
    }
    vector<vector<bool>> dp(N+1,vector<bool>(S+1,false));
    dp[0][0]=true;
    
    rep(i,N){
        rep(j,S+1){
            if(!dp[i][j]) continue;
            dp[i+1][j+T[i]] = true;
            dp[i+1][j] = true;
        }
    }
    
    /*
    rep(i,N+1){
        rep(j,S+1){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/    
    
    int ans = S;
    
    for(int j=S-S/2;j<=S;++j){
        if(dp[N][j]){
            ans = j;
            break;
        }
    }
    cout << ans << endl;
}
