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
int main(){
    ll N;
    cin >> N;
    map<string,ll> mp;
    rep(i,N){
        string s;
        cin >> s;
        mp[s]++;
    }
    ll mx = -1;
    vector<pair<ll,string>> pr;
    for (auto itr = mp.begin();itr != mp.end() ; itr++ ){
        pr.push_back({-itr->second,itr->first});
        chmax(mx,itr->second);
    }
    // cout << " " << endl;

    sort(pr.begin(),pr.end());
    rep(i,pr.size()){
        if(mx>-pr[i].first) break;
        cout << pr[i].second << endl;
    }
}
