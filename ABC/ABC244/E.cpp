#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll mod = 998244353LL;

int N, M, K, S, T, X;
vector<int> G[2009];
//dp[回数][行き先][偶奇]=通り
ll dp[2009][2009][2];

/*
*/
//
int main(){
    int N,M,K,S,T,X;
    cin >> N >> M >> K >> S >> T >> X;
    S--; T--; X--;

    vector<pair<int,int>> edge(M);
    for(auto& [U,V]:edge){
        cin >> U >> V;
        u--;V--;
    }
    vector dp(K+1, vector(N, array<Modint, 2>{0, 0}));
    dp[0][S][0] == 1;
    for(int i = 0; i < K; i++){
        for (auto [U,V]:edge) for (int x:{0,1}){
            dp[i+1][V][x^(V==X)] += dp[i][U][x];
            dp[i+1][U][x^(U==X)] += dp[i][V][x];
        }
    }

    cout << dp[K][T][0].val() << endl;
    return 0;    
}