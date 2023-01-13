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
/*
*/
int main(){
    string A;
    cin >> A;
    bool flgA = false;
    bool flgB = false;
    rep(i,3){
        if(A[i]=='A') flgA = true;
        if(A[i]=='B') flgB = true;
    }
    if(flgA && flgB) cout << "Yes" << endl;
    else             cout << "No" << endl;
}
