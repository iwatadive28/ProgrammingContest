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
    ll N;
    cin >> N;
    vector<int> A(N,0);
    rep(i,N) cin >> A[i];
    
    ll ans = 0;
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            ll M = j-i+1;
            ll res = 0;
            if(M > 1){
                rep(k,M/2){
                    if (A[i+k] != A[i+M-1-k]) res++;
                }
            }
            ans += res;            
        }
    }    
    cout << ans << endl;
}