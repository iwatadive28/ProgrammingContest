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
    rep(i,N) cin >> A[i];

    int ans = 2000000000;
    for(int i=0;i<(1<<N-1);i++){ // 区間 0~i,i+1~N-1
        int ord  = 0;
        int xord = 0;
        rep(j,N+1){
            if(j<N) ord |= A[j];
            if(j==N||(i>>j&1)) xord ^= ord,ord =0;
        }
        ans = min(xord,ans);
    }
    cout << ans << endl;
}
