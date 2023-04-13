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
    ll N;
    cin >> N;
    ll X = 0;
    vector<ll> C(N);
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        X-=a;
        C[i] = -(2*a+b);
    }
    sort(C.begin(),C.end());
    ll ans = 0;
    rep(i,N){
        X -= C[i];
        if(X>0){
            ans = i+1;
            break;
        }
    }
    cout << ans << endl;
}