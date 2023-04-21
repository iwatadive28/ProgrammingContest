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
// 割り切れる数を探す
// 素因数分解
vector<pair<ll,pair<ll,ll>>> pfact(ll x){
    // O(sqrt(x))
    vector<pair<ll,pair<ll,ll>>> res;
    for (ll i=1;i*i<=x;i++){
        if(x%i==0){
            res.push_back({i+x/i-2,{i,x/i}});
        }
    }
    return res;
}

int main(){
    ll N;
    cin >> N;

    ll ans = N-1;
    vector<pair<ll,pair<ll,ll>>> vc = pfact(N);
    sort(vc.begin(),vc.end());
    ans = vc[0].first;
    cout << ans  << endl;
}