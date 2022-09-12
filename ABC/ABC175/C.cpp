#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    ll X,K,D;
    cin >> X >> K >> D;
    X = abs(X);

    ll straight = min(K, X / D);
    K -= straight;
    X -= straight * D;

    ll ans;
    if(K%2 == 0){
        ans = X;
    }else{
        ans = D-X;
    }

    cout << ans << endl;
}
