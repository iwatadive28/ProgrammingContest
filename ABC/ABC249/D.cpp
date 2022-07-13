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
constexpr int MAX = 200000;
 
int main() {
    int n;
    cin >> n;
    vector<int> c(MAX + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x] += 1;
    }
    ll ans = 0;
    for (int q = 1; q <= MAX; ++q) {
        for (int r = 1; q * r <= MAX; ++r) {
            ans += (ll) c[q] * c[r] * c[q * r];
        }
    }
    cout << ans << endl;
    return 0;
}