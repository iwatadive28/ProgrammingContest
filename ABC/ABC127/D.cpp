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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);

    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end());

    vector<pair<ll,ll>> cb(M);
    rep(i,M){
        ll b,c;
        cin >> b >> c;
        cb[i] = {-c,b};
    }
    sort(cb.begin(),cb.end());

    vector<ll> D(N);
    ll ds = 0;
    rep(i,M){
        // cout << cb[i].second << "," << -cb[i].first << endl;
        rep(j,cb[i].second){
            D[ds] = -cb[i].first;
            ds++;
            if(ds>=N) break;
        }
        if(ds>=N) break;
    }
       
    rep(i,ds){
        if(A[i]>=D[i]) break;
        A[i] = D[i];
    }
    
    ll ans = 0;
    rep(i,N) ans += A[i];
    
    cout << ans << endl;
    
}
