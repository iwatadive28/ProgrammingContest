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
    // 入力
    ll W,H;
    cin >> W >> H;
    ll N;
    cin >> N;
    vector<ll> p(N),q(N);
    rep(i,N) cin >> p[i] >> q[i];
    
    ll A;
    cin >> A;
    vector<ll> a(A);
    rep(i,A) cin >> a[i];
    a.push_back(W);

    ll B;
    cin >> B;
    vector<ll> b(B);
    rep(i,B) cin >> b[i];
    b.push_back(H);
    // ** ここまで入力

    sort(a.begin(),a.end()); // ,greater<ll>()
    sort(b.begin(),b.end()); // ,greater<ll>()
    map<pair<ll,ll>,ll> mp;
    rep(i,N){
        ll itera = upper_bound(a.begin(),a.end(),p[i])-a.begin();
        ll iterb = upper_bound(b.begin(),b.end(),q[i])-b.begin();
        mp[{itera,iterb}]++;
    }

    ll m = N,M = 0;
    for(auto p:mp) chmax(M,p.second);
    if(mp.size() == (A+1)*(B+1)){
        for(auto p:mp) chmin(m,p.second);
    }else{
        m = 0;
    }
    cout << m << " " << M << endl;
}