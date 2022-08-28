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
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> B(N,vector<ll>(M));
    rep(i,N) rep(j,M) cin >> B[i][j];
    
    ll j1;
    if (B[0][0]%7==0) j1 = 7;
    else              j1 = B[0][0]%7;
    ll i1;
    if (B[0][0]%7==0) i1 = B[0][0]/7-1;
    else              i1 = B[0][0]/7;
    cout << endl;
    // O(7*10^4)
    bool ans = true;
    rep(i,N){
        rep(j,M){
            ll tmp = ((i1+i)*7)+(j1+j);
            cout << tmp << " ";
            if (B[i][j] != tmp){                
                ans = false;
                break;
            }
        }
        cout << endl;
        if(!ans) break;                
    }
    cout << (ans?"Yes":"No") << endl;    
}