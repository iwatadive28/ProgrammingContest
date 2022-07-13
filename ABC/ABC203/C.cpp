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
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>> AB(N);
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        AB[i] = make_pair(a,b);
    }
    sort(AB.begin(),AB.end());

    ll x = 0;
    rep(i,N){
        ll a = AB[i].first;
        ll b = AB[i].second;
        if (K-(a-x)>=0){
            K = K-(a-x)+b;
            x = a;
        }else{
            x = x+K;
            break;
        }
        // cout << x << ":" << K << endl;
    }
    
    if (x>=AB[N-1].first & K>0) x+=K;

    cout << x << endl;
}
