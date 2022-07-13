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
    map<string,pair<ll,ll>> mp;
    rep(i,N){
        string s;
        ll t;
        cin >> s >> t;
        // 見つからない場合はスコアを代入
        if (mp.find(s) == mp.end()){
            mp[s] = make_pair(t,i+1);
        }
    }

    int tmx = 0;
    int ans = 0;

    for (auto itr = mp.begin();itr != mp.end() ; itr++ ){
        if (tmx < itr->second.first){
            tmx = itr->second.first;
            ans = itr->second.second;
        }
    }

    cout  << ans << endl;    
}