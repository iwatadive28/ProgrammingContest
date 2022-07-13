#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
const int INF = 20000000;
 
int main(){
     // 入力
    ll N,M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i,N) cin >> P[i];
    P.push_back(0);
    
    // 初期化 
    vector<ll> S;
    rep(i,N+1){
        rep(j,N+1){
            S.push_back(P[i] + P[j]);            
        }
    }
    sort(S.begin(),S.end());
    
    ll res = 0;
    rep(i,S.size()){
        // 集合 S の要素のうち、M−S[i]以下の範囲での最大値を求めよ
        // - M-S[i]より大きい値のうち、最も小さい値
        auto it = upper_bound(S.begin(),S.end(),M-S[i]); 
        if (it == S.begin()) continue;
        --it; // M-S[i]以下の最大値
        
        // 最大値かどうか判定
        res = max(res,S[i]+*it);
    }
    cout << res << endl;

    return 0;
}