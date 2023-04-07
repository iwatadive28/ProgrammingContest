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
ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
     return res;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> s(M),c(M);
    rep(i,M) cin >> s[i] >> c[i];

    int ans = -1;
    for(ll n=0;n<mypow(10,N);n++){
        string num = to_string(n);
        if(num.length()<N) continue;
        
        bool ok = true;
        rep(i,M){
            if((num[s[i]-1]-'0')!=c[i]) ok = false;
        }

        if(ok){
            ans = n;
            break;
        }
    }

    cout << ans << endl;
}