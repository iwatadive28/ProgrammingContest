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
//

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> H(N,0);
    rep(i,N) cin >> H[i];
    
    vector<bool> B(N,true);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--;b--;

        if      (H[a]>H[b])  B[b] = false;
        else if (H[a]<H[b])  B[a] = false;
        else if (H[a]==H[b]) B[a] = false,B[b] = false;
    }
    
    ll ans = 0;
    rep(i,N){
        // cout << B[i] << endl;
        if(B[i]) ans++;
    }
    cout << ans << endl;
}