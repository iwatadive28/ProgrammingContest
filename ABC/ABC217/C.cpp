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
    int N;
    cin >> N;
    vector<int> q(N);
    rep(i,N) {
        int p;
        cin >> p;
        q[p-1] = i+1;
    }

    rep(i,N) cout << q[i] << " ";
    cout << endl; 
}