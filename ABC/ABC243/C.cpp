#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    ll n;
    cin >> n;
    vector<ll> x(n),y(n);
    string s;
    rep(i,n) cin >> x[i] >> y[i];
    cin >> s;

    map<ll,pair<ll,ll>> mp; // y：(right_min,left_max)
    rep(i,n){
        pair<ll,ll> pr = make_pair(1000000010,-1); // 右向く人の中で最小, 左向く人の中で最大
        mp[y[i]] = pr;
    }
    rep(i,n){
        if(s[i]=='R'& x[i] < mp[y[i]].first)  mp[y[i]].first  = x[i];
        if(s[i]=='L'& x[i] > mp[y[i]].second) mp[y[i]].second = x[i];
    }

    //
    bool ans = false; 
    for (auto itr = mp.begin();itr != mp.end() ; itr++ ){
        pair<ll,ll>& pr = itr->second;
        if(pr.first < pr.second){
            ans = true;
            // cout << itr->first << ","<<  pr.first << " " <<  pr.second << endl;
            break;
        }
    }
    cout << (ans?"Yes":"No") << endl;
}