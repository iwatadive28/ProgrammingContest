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
    ll N,W;
    cin >> N >> W;
    vector<pair<ll,ll>> pr(N);
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        pr[i] = make_pair(-a,b);
    }
    sort(pr.begin(),pr.end());

    ll ans = 0;
    rep(i,N){
        ll a = -pr[i].first,b = pr[i].second;
        ll n = min(b,W);
        ans += a*n;
        W -= n;
    }

    cout << ans << endl;
}