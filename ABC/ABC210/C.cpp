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
    vector<ll> c(N);
    rep(i,N) cin >> c[i];

    map<ll,int> mp;
    // 初期設定
    rep(i,K){
        // 見つからない場合は初期化
        if (mp.find(c[i]) == mp.end()){
            mp[c[i]] = 1;
        }else{
            mp[c[i]]++;
        }
    }

    int ans = mp.size();
    mp[c[0]]--;
    if(mp[c[0]]==0) mp.erase(c[0]);
    
    for(int i=1;i<N-K+1;++i){
        // 見つからない場合は初期化
        if (mp.find(c[i+K-1]) == mp.end()){
            mp[c[i+K-1]] = 1;
        }else{
            mp[c[i+K-1]]++;
        }
        
        if(ans<mp.size()) ans = mp.size();
        
        // 削除
        mp[c[i]]--;
        if(mp[c[i]]==0) mp.erase(c[i]);
    }

    cout << ans << endl;
}