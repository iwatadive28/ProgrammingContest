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
    vector<int> A(N);
    int M = 0;
    rep(i,N){
        cin >> A[i];
        chmax(M,A[i]);
    }

    int ans = 0;
    int cmx = 0;
    for(int j=2;j<=M;++j){
        int cnt = 0;
        rep(i,N) if(A[i]%j==0) cnt ++;
        if(cnt>cmx){
            ans = j;
            cmx = cnt;
        }
    }
    cout << ans << endl;
}
