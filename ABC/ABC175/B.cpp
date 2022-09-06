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
    int N;
    cin >> N;
    vector<ll> L(N);
    rep(i,N) cin >> L[i];
    sort(L.begin(),L.end());

    ll ans = 0;
    for(ll i = 0;i<N-2;++i){
        for(ll j=i+1;j<N-1;++j){
            for(ll k=j+1;k<N;++k){
                if(L[i]!=L[j] && L[j]!=L[k] && L[i]+L[j]>L[k]) ans++;
            }
        }
    }
    
    cout << ans << endl;
}
