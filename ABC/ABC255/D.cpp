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
    ull N,Q;
    cin >> N >> Q;
    vector<ull> A(N),X(Q);

    rep(i,N) cin >> A[i];
    rep(i,Q) cin >> X[i];
    sort(A.begin(),A.end());
    vector<ull> S(N,0); // iまでの累積和
    rep(i,N) {
        if (i==0) S[i] += A[i];
        else      S[i] += A[i] + S[i-1];
    }
    // rep(i,N) cout << S[i] << endl;
    
    rep(i,Q){
        ull x = X[i];
        ull ans=0;
        
        if(x<A[0]){
            ans = S[N-1] - x*N;
        }else if(x>A[N-1]){
            ans = x*N - S[N-1];
        }else{
            ull iter = upper_bound(A.begin(),A.end(),x)-A.begin();
            ans += iter*x - S[iter-1];
            ans += S[N-1]-S[iter-1]-(N-iter)*x;
        }
        cout << ans << endl;
    }
}
