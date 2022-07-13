#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    
    //
    vector<int> B(N+2);
    B[0] = 0;
    rep(i,N){
        B[i+1] = (B[i] + A[i])%360;
    }
    B[N+1] = 360;
    sort(B.begin(),B.end());
    int ans = -1;
    rep(i,N+1){
        if (ans < B[i+1]-B[i]){
            ans = B[i+1]-B[i];
        }        
    }    
    cout << ans << endl;
    
}