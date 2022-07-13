#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
const int INF = 20000000;
 
int main(){
     // 入力
    ll N;
    cin >> N;
    vector<ll> A(N),B(N),C(N);

    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N) cin >> C[i];

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    ll ans = 0;    
    rep(i,N){
        ll a = lower_bound(A.begin(),A.end(),B[i]) - A.begin();
        ll c = C.end() - upper_bound(C.begin(),C.end(),B[i]);
        ans += a*c;
    }
    cout << ans << endl;
    /*
    rep(i,N) cin >> C[i];
    sort(C.begin(),C.end());
    
    int a;
    cin >> a;
    ll c = C.end() - upper_bound(C.begin(),C.end(),a);
    cout << c << endl;
    */
    return 0;
}