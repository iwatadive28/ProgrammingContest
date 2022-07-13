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
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    vector<pair<ll,char>> pr; 
    rep(i,N){
        ll w;
        cin >> w;
        pr.push_back({w,S[i]});
        if(S[i]=='1') ans++; // 大人をカウントしておく
    }
    sort(pr.begin(),pr.end());
    
    ll x = ans;
    rep(i,N){
        
        if(pr[i].second == '1') x--;// 大人ならカウントダウン
        else x++;// 子供ならカウントアップ
        if (i<(N-1)) {
            if (pr[i].first != pr[i+1].first)ans = max(ans, x);
        }
        else ans = max(ans,x);
    }
    cout << ans << endl;
}
