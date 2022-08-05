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
    int N,X;
    cin >> N >> X;
    
    int sum = 0;
    rep(i,N){
        int v,p;
        cin >> v >> p;
        sum += v*p;
        if(sum>X*100){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
