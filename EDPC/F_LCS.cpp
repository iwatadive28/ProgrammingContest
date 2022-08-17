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
    string s,t;
    cin >> s >> t;
    int N = s.size();
    int M = t.size();
    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    dp[0][0] = 0;
    
    // 貰うDP
    for(int i=1;i<=N;++i){
        int mxtmp = 0;
        for(int j=1;j<=M;++j){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    /*
    rep(i,N+1){
        rep(j,M+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    
    // 文字はDP配列を逆から辿る
    string ans = "";
    int i = N;
    int j = M;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);
            i--,j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
        
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
