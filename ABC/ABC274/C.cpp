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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=1;i<=N;++i) cin >> A[i];

    vector<int> ans(2*N+2,0);
    ans[A[1]] = 0;
    for(int i=1;i<=N;++i){
        ans[2*i]   = ans[A[i]]+1;
        ans[2*i+1] = ans[A[i]]+1;
    }
    
    for(int i=1;i<=2*N+1;++i){
        // cout << par[i]<< endl;
        cout << ans[i] << endl;
    }
}
