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
    
    ll ja = (B[0][0]-1)%7;
    ll ia = (B[0][0]-1)/7;
    vector<vector<ll>> A(N,vector<ll>(M));

    bool ans = true;
    if(ja+M>7) ans = false;
    // O(7*10^4)
    rep(i,N){
        rep(j,M){
            ll a = (i+ia)*7+(ja+j+1);
            A[i][j] = a;
        }
    }

    // rep(i,N) {rep(j,M){cout << A[i][j] << " ";}cout << endl;};

    // O(7*10^4)
    rep(i,N){
        rep(j,M){
            if (B[i][j] != A[i][j]){                
                ans = false;
            }
        }
    }
    cout << (ans?"Yes":"No") << endl;    
}