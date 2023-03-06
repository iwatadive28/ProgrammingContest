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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    // マンハッタン距離
    // 45度回転
    vector<ll> A(N,0);
    ll Xmax=-INF,Xmin=INF,Ymax=-INF,Ymin=INF;
    rep(i,N){
        ll X = x[i]-y[i];
        ll Y = x[i]+y[i];
        chmax(Xmax,X);
        chmin(Xmin,X);
        chmax(Ymax,Y);
        chmin(Ymin,Y);
    }

    // cout << Xmax << "," << Xmin << endl;
    // cout << Ymax << "," << Ymin << endl;

    //
    vector<ll> ans(Q);
    rep(i,Q){
        // 45度回転
        ll q; cin >> q; q--;
        ll X = x[q]-y[q];
        ll Y = x[q]+y[q];

        // 最も遠い点を求める
        ll tmp = -1;
        chmax(tmp,abs(Xmax-X));
        chmax(tmp,abs(Xmin-X));
        chmax(tmp,abs(Ymax-Y));
        chmax(tmp,abs(Ymin-Y));
        ans[i] = tmp;
    }

    rep(i,Q) cout << ans[i] << endl;
}