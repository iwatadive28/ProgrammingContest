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
    int V,T,S,D;
    cin >> V >> T >> S >> D;

    bool ans = true; 
    if(V*T<=D && D<=V*S ) ans = false;
    cout << (ans?"Yes":"No") << endl;
}
