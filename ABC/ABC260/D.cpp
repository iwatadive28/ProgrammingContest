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
    vector<int> ans(N+1,-1);
    
    map<int,vector<int>> mp;
    rep(i,N){
        int p;
        cin >> p;
        auto it = mp.lower_bound(p); // mapキーのうちp以上で最小の値のポインタを返す
        if (it != mp.end()){ 
            mp[p] = move(it->second); // キーp以下に最小のmpを与える
            mp.erase(it); 
        }
        mp[p].push_back(p); // pを追加
        if(mp[p].size()==K){
            for(auto j:mp[p]) ans[j]=i+1;
            mp.erase(p);
        }
    }

    rep(i,N){
        cout << ans[i+1] << endl;
    }
    
}
