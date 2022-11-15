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
    ll n,m,sum=0;
    cin >> n >> m;
    map<ll,ll> mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
        sum+=a;
    }

    vector<pair<ll,ll>> vec;
    for(auto p:mp) vec.push_back(p);
    int k = vec.size();

    // m種類の整数がすべてある場合
    if(k>=m){
        cout << 0 << endl;
        return 0;
    }

    // 初手を探す.次の大きい数を出せなくなるものから始める.
    int p;
    rep(i,k){
        if(vec[(i+1)%k].first != (vec[i].first+1)%m){
            p = i;
            break;
        }
    }

    vector<ll> s(k,sum);
    rep(i,k){
        // j は減っていく
        int j = (p-i+k)%k; 
        s[j] = sum;
        // 手札を出せる場合、前のs[j]から操作を続ける
        if(vec[(j+1)%k].first == (vec[j].first+1)%m) s[j] = s[(j+1)%k]; 
        s[j] -= vec[j].first * vec[j].second;
    }

    ll ans = sum;
    rep(i,k) chmin(ans,s[i]);
    cout << ans << endl;

}
