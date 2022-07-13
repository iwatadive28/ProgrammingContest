#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
#define Yes cout << "Yes" << endl
#define No  cout << "No"  << endl
/*
*/
//
int main(){
    vector<vector<int>> c(3,vector<int>(3));
    rep(i,3) rep(j,3) cin >> c[i][j];
    
    vector<int> a(3,110);
    rep(i,3) rep(j,3) a[i] = min(a[i],c[i][j]);
    rep(i,3) rep(j,3) c[i][j]-=a[i];
    
    bool ans = true;
    rep(j,3) rep(i,2){
        if (c[i][j] != c[i+1][j] ){
            ans = false;
            break;
        }
    }
    if(ans) Yes;
    else No;
}
