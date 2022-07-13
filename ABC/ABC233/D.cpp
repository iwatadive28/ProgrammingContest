#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> S(N+1,0);
    rep(i,N) S[i+1] = S[i]+A[i];
    // l-rの区間和 = S[r]-S[l-1]
    // S[r]-K = S[l-1]
    
    map<ll,ll> mp;
    ll cnt = 0;
    for(ll r=1;r<=N;++r){
        // 右辺 S[l-1] をカウント
        mp[S[r-1]]++;
        // 左辺 S[r]-K が右辺と同じになる数をカウント
        cnt += mp[S[r]-K];
    }
    cout << cnt << endl;

}