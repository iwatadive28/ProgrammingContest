#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    map<string,bool> mp;
    mp["ABC"] = true;
    mp["ARC"] = true;
    mp["AGC"] = true;
    mp["AHC"] = true;
    
    rep(i,3){
        string s;
        cin >> s;
        mp[s] = false;
    }

    for (auto itr = mp.begin();itr != mp.end() ; itr++ ){
        if (itr->second){
            cout << itr->first << endl;
            break;
        }
    }
    
}