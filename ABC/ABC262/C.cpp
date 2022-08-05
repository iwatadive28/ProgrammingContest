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
ll comb(int n,int m){
    ll C = 1;
    ll c = 1;
    rep(i,m) C*=(n-i);
    rep(i,m) c*=(m-i);
    
    C/=c;
    return C;
}

int main(){
    int N;
    cin >> N;
    
    int ca = 0;
    int cb = 0;
    vector<int> A(N+1,-1);
    rep(i,N){
        int a;
        cin >> a;
        A[i+1] = a;
        if (a==i+1) ca++;
        else if (A[a]==i+1) cb++;
    }

    // cout << ca << "," << cb << endl;
    ll ans = comb(ca,2) + cb;
    cout << ans << endl;   
}
