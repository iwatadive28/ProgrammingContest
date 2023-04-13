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
//
int main(){
    ll N;
    cin >> N;
    vector<ll> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];

    map<ll,set<ll>> mpx;
    rep(i,N) mpx[x[i]].insert(y[i]);
    
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    ll K = x.size();
    
    ll ans = 0;
    rep(i,K-1){
        for (ll j=i+1; j<K; j++){
            ll cnt = 0;
            for(auto itr = mpx[x[i]].begin(); itr != mpx[x[i]].end(); ++itr) {
                if(mpx[x[j]].count(*itr)){
                    cnt++;
                }
            }
            ans += (cnt*(cnt-1)/2);
        }
    }
    cout << ans << endl;
}