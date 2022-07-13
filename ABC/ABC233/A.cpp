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
ll max(double a, double b){
    if(a>b) return a;
    else    return b;
}

ll ceil(ll a,ll b){return (a+b-1)/b;}

int main(){
    double X,Y;
    cin >> X >> Y;
    int ans;

    ans = max(0,ceil((Y-X)/10));
    cout << ans << endl;
}