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
    int N,K,Q;
    cin >> N >> K >> Q;
    vector<int> A(K);
    vector<bool> M(N+1,false);
    rep(i,K) {
        cin >> A[i];
        M[A[i]] = true;
    }

    rep(i,Q){
        int l;
        cin >> l;
        l--;
        // L[i] が一番左か？
        if (A[l]==N) continue;
        // L[i]の右に駒があるか？
        if (M[A[l]+1]) continue;

        M[A[l]] = false;
        A[l]++;
        M[A[l]] = true;
    }

    rep(i,N+1){
        if(M[i]) cout << i << " ";
    }
    cout << endl;
    // cout << ans << endl;
}
