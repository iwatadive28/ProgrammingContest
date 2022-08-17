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
    int N;
    cin >> N;
    vector<ll> x(N);
    rep(i,N) cin >> x[i];

    ll dm = 0, dc = 0;
    ll dj1 = 0;
    rep(i,N){
        dm += abs(x[i]);
        chmax(dc,abs(x[i]));
        dj1 += x[i]*x[i];
    }
    double dj = sqrt(dj1);

    cout << dm << endl;
    printf("%.9f\n",dj);
    cout << dc << endl;
}
