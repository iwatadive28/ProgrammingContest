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
    int N; cin >> N;
    vector<double> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];
    double t = 0, ans = 0;
    rep(i,N) t += A[i] / B[i];
    t /= 2;
    rep(i,N){
        ans += min(A[i], t * B[i]);
        t -= min(A[i] / B[i], t);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}