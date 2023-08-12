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
    int N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> A(N);
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        A[i] = {a,b};
    }
    sort(A.begin(),A.end()); // ,greater<ll>()

    ll ans = 0;
    rep(i,N){
        ll a = A[i].first;
        ll b = A[i].second;
        if(M>=b){
            ans += a*b;
            M-=b;
        }else{
            ans += a*M;
            M = 0;
        }
        if(M==0){
            break;
        }
    }
    cout <<  ans << endl;
}