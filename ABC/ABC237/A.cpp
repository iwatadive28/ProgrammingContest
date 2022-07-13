#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    ll N;
    cin >> N;

    bool ans = true;
    if (N >= 2147483648 ) ans = false;
    if (N < -2147483648 ) ans = false;

    cout << (ans?"Yes":"No") << endl;
}