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
    int x,y,z;
    cin >> x >> y;
    if (x==y) z = x;
    else{
        vector<bool> a(3,true);
        a[x] = false;
        a[y] = false;
        rep(i,3) if(a[i]) z=i;
    }
    cout << z << endl;
}
