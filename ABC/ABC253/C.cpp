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
    ll Q;
    cin >> Q;

    vector<ll> ans;
    map<ll,ll> S;
    rep(i,Q){
        int q,c;
        ll x;
        cin >> q;
        
        if (q == 1){
            cin >> x;
            S[x]++;

        }else if (q == 2){
            cin >> x >> c;
            if (S[x]<=c) S.erase(x);
            else S[x] -= c;

        }else if (q == 3){
            ans.push_back(S.rbegin()->first -  S.begin()->first);
        }
    }

    for(ll a : ans) cout << a << endl;
  
}