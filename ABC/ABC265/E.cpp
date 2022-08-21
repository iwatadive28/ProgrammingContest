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
const ll MOD = 998244353; //10^9 + 7
/*
*/
//
int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<int,int>> dxy(N);
    rep(i,3){
        int a,b;
        cin >> a >> b;
        dxy[i] = {a,b};
    }
    
    set<pair<int,int>> S;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		S.insert({a,b});
	}

    map<pair<ll,ll>,ll> dp;
    dp[{0,0}] = 1;
    // O(N)
    rep(i,N){
        map<pair<ll,ll>,ll> new_dp;
        for (auto itr = dp.begin();itr != dp.end() ; itr++ ){
            pair<ll,ll> xy = itr->first;
            ll x = xy.first;
            ll y = xy.second;
            ll val = itr->second;

            // cout <<x<<","<<y <<":"<< val << endl;
            // O(3)
            rep(j,3){
                int dx = dxy[j].first;
                int dy = dxy[j].second;                
                // O(MlogM)
                if(S.find({x+dx,y+dy})==S.end()){ 
                    new_dp[{x+dx,y+dy}]+=val; // 壁がない
                    new_dp[{x+dx,y+dy}]%=MOD;
                    // cout <<x+dx<<","<<y+dy <<":"<< new_dp[{x+dx,y+dy}]<< endl;
                }
            }
        }
        swap(dp,new_dp); // dp を更新
    }

    ll ans = 0;
    for (auto itr = dp.begin();itr != dp.end() ; itr++ ){
        // cout <<x<<","<<y <<":"<< val << endl;
        ans+=itr->second;
        ans%=MOD;
    }
    cout << ans << endl;
}
