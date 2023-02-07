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

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    /*
    // 累積和
    vector<ll> sum(N+1,0);
    rep(i,N) sum[i+1] = sum[i]+A[i];
    rep(i,N+1) cout << sum[i] << " ";
    cout << endl;
    */   
    
    ll Q;
    cin >> Q;


    vector<bool> ans(Q,false);
    rep(q,Q){
        ll l,r;
        cin >> l >> r;
        l--;r--;
        ll m = r-l+1;
        vector<ll> B = A;
        rep(i,m-K+1){
            ll a = B[l+i];
            rep(k,K){
                B[l+i+k]-=a;
            }
        }
        bool tmp = true;
        rep(i,m) {
            cout << B[l+i] << " ";
            if(B[i]!=0) tmp = false;
        }
        cout << endl;
        ans[q] = tmp;
    }

    rep(i,Q) cout << (ans[i]?"Yes":"No") << endl;
    
}
