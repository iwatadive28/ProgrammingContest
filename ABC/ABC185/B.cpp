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
    int N,M,T;
    cin >> N >> M >> T;
    vector<int> A(M),B(M);
    rep(i,M) cin >> A[i] >> B[i];
    
    int bt = N;
    int pb = 0;
    bool ans = true;
    rep(i,M){
        bt+=(pb-A[i]);
        // cout << A[i] << ":" << bt << endl;
        if(bt<=0){
            ans = false;
            break;
        }
        bt+=(B[i]-A[i]);
        if (bt>N) bt=N;
        // cout << B[i] << ":" << bt << endl;
        pb = B[i];

    }
    bt+=(pb-T); 
    if(bt<=0) ans = false;
        
    cout << (ans?"Yes":"No") << endl;
    // cout << bt << endl;
}
