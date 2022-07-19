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
    int N,X,Y;
    cin >> N >> X >> Y;
    ll ans = 0;
    vector<ll> r(N+1,0),b(N+1,0);
    r[N]=1;

    for(int i=N;i>1;--i){
        // 操作1
        r[i-1] += r[i];
        b[i] += r[i]*X;

        // 操作2
        r[i-1] += b[i];
        b[i-1] += b[i]*Y;
    }

    cout << b[1] << endl;
}
