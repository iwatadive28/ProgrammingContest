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

int main(){
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> pr(N);
    ll sum = 0;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        pr[i] = {a,b};
        sum += b;
    }
    sort(pr.begin(),pr.end()); // ,greater<ll>()
    ll ans = 1;
    ll i = 0;
    while(sum>K){
        sum-=pr[i].second;
        if(sum<=K){
            ans = pr[i].first+1;
            break;
        }
        i++;
    }
    cout << ans << endl;
}