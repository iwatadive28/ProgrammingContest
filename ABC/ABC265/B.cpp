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
    ll N,M,T;
    cin >> N >> M >> T;
    vector<ll> A(N);
    rep(i,N-1) cin >> A[i];

    vector<ll> Z(N,0); // 0~N-1
    rep(i,M){
        ll x,y;
        cin >> x >> y;
        Z[x-1] = y;
    }

    bool ans = true;
    rep(i,N-1){
        T += Z[i];
        T -= A[i];
        if(T<=0) {
            ans = false;
            break;
        }
    }

    cout << (ans?"Yes":"No") << endl;
}
