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
ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];

    set<pair<ll,ll>> st;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            if(i==j) continue;
            ll a = x[i]-x[j];
            ll b = y[i]-y[j];
            ll c;
            if(a!=0&&b!=0) c = gcd(abs(a),abs(b));
            else c = max(abs(a),abs(b));

            // cout << a << "," << b << "," << c << endl;
            if(!st.count({a/c,b/c})){
                st.insert({a/c,b/c}); 
            }
        }
    }

    cout << st.size() << endl;
}