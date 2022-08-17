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
    ll X,Y,A,B;
    cin >> X >> Y >> A >> B;
    ll ans = 0;
    while((double)A*X<=2e18 && X*A<=X+B && A*X<Y){
        X*=A;
        ans++;
    }
    ans += (Y-1-X)/B;
        
    cout << ans << endl;
}
