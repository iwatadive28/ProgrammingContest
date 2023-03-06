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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];

    map<ll,ll> mp;
    ll ans = -1;

    // 尺取り法
    ll r=0;
    ll cnt=0; // 連続するユニークな数
    rep(l,N){
        while(r<N){
            if (mp[A[r]]==0 && cnt==K) break;
            if (mp[A[r]]==0) cnt++;
            mp[A[r]]++;
            r++;
        }
        chmax(ans,r-l);
        mp[A[l]]--; // 一番左の数を削除する
        if(mp[A[l]]==0) cnt--; // その種類がなくなった場合
    }

    cout << ans << endl;
}