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
static const double pi = 3.141592653589793;
const double deg = pi/180;
int main(){
    double a,b,a1,b1,d;
    cin >> a >> b >> d;

    a1 = a*cos(d*deg) - b*sin(d*deg);
    b1 = a*sin(d*deg) + b*cos(d*deg);

    printf("%.7f %.7f\n",a1,b1);
    // cout << a1 << " " << b1 << endl;
}
