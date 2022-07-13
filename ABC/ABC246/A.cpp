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
    vector<int> x(3),y(3);
    rep(i,3) cin >> x[i] >> y[i];

    int xa,ya;
    if      (x[0] == x[1]) xa = x[2]; 
    else if (x[1] == x[2]) xa = x[0]; 
    else if (x[2] == x[0]) xa = x[1]; 

    if      (y[0] == y[1]) ya = y[2]; 
    else if (y[1] == y[2]) ya = y[0]; 
    else if (y[2] == y[0]) ya = y[1]; 
    cout << xa << " " << ya << endl;    
}