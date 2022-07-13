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
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> A(H,vector<ll>(W));
    rep(i,H){
        rep(j,W) cin >> A[i][j];
    }

    rep(j,W){
        rep(i,H){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}