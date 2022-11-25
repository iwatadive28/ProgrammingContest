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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    ll n,q;
    cin >> n >> q;
    vector<bool> ans;
    map<ll,set<ll>> mp;
    rep(i,q){
        
        int t,a,b;
        cin >> t >> a >> b;
        a--;b--;
        
        if(t==1){
            mp[a].insert(b);
        }
        if(t==2){
            mp[a].erase(b);
        }
        if(t==3){
            ans.push_back(mp[a].count(b)&&mp[b].count(a));
        }
        
    }
    
    for(auto yn:ans) cout << (yn?"Yes":"No") << endl;
}
