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
//
int main(){
    vector<int> a(14,0);
    rep(i,5){
        int b;
        cin >> b;
        a[b]++;
    }
    string ans = "Yes";
    rep(i,14){
        if(a[i]!=0 && a[i]!=2 && a[i]!=3) ans = "No";
    }
    cout << ans << endl;   
}