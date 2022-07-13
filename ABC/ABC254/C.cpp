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
    int N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<vector<ll>> B(K);
    rep(i,N){
        B[i%K].push_back(A[i]);
    }

    rep(i,K){
        sort(B[i].begin(),B[i].end());
    }

    rep(i,N){
        A[i] = B[i%K][i/K];
        // cout << A[i] << " ";
    }
    // cout << endl;


    bool ans = true;
    rep(i,N-1) { 
        if(A[i]>A[i+1]){
            ans = false;
            break;
        }
    }

    
    cout << (ans?"Yes":"No") << endl;
}
