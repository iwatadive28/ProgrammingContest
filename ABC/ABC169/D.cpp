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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

// 素因数分解
vector<pair<ll,ll>> pfact(ll x){
    // O(sqrt(x))
    vector<pair<ll,ll>> res;
    for (ll i=2;i*i<=x;++i){
        if(x%i!=0) continue;
        ll ex = 0;
        while(x%i==0){
            ++ex;
            x/=i;
        }
        res.push_back({i,ex});
    }
    if (x != 1) res.push_back({x, 1});
    return res;
}

int main(){
    ll N;
    cin >> N;

    // 素因数分解
    vector<pair<ll,ll>> vc = pfact(N);
    sort(vc.begin(),vc.end());

    ll ans = 0;
    for(auto v:vc){
        ll x   = v.first;
        ll cnt = v.second;
        // cout << x << "**" << cnt << endl;

        for(int i=1;i<=cnt;++i){
            if(i<=cnt){
                ans++;
                cnt-=i;
            }else{
                break;
            }
        }
        
    }
    cout << ans << endl;
}