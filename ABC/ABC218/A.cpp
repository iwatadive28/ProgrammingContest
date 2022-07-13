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
 
int main() {
    int N;
    string S;
    cin >> N >> S;

    bool ans = false;
    if (S[N-1]=='o') cout << "Yes" << endl;
    else             cout << "No"  << endl;
}