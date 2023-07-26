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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    vector<int> A(5,0);
    int mnidx = 0;
    int mn    =10;
    rep(i,5){
        cin >> A[i];
        if(chmin(mn,(A[i]-1)%10)) mnidx = i;
    }
    
    int ans = 0;
    rep(i,5){
        if(i==mnidx) continue;
        if(A[i]%10!=0) A[i]=(A[i]/10+1)*10;
        ans += A[i];        
    }
    ans += A[mnidx];
    cout << ans << endl;
}