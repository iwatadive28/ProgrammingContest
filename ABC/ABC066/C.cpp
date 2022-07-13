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
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    
    vector<int> a0,a1;
    rep(i,N){
        if (i%2==0) a0.push_back(a[i]);
        else        a1.push_back(a[i]);
    }

    vector<int> b0,b1;
    if (N%2==0){
        b0 = a1;
        b1 = a0;
    }else{
        b0 = a0;
        b1 = a1;
    }
    rep(i,b0.size()) cout << b0[b0.size()-i-1] << " ";
    rep(i,b1.size()) cout << b1[i] << " ";
    cout << endl;

}
