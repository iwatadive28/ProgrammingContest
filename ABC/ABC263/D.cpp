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
    ll N,L,R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    ll sum = 0;
    rep(i,N) {
        cin >> A[i];
        sum += A[i];
    }

    //
    vector<ll> l(N,0),r(N,0);
    vector<ll> lmin(N),rmin(N);
    ll mn = INF;
    rep(i,N){
        if(i==0) l[i] = L-A[i];
        else     l[i] = l[i-1]+(L-A[i]);
        // i までの最小値
        chmin(mn,l[i]);
        lmin[i] = mn;
    }
    // rep(i,N) cout << l[i] << " ";
    // cout << endl;

    mn = INF;
    rep(i,N){
        if(i==0) r[i] = R-A[N-i-1];
        else     r[i] = r[i-1]+(R-A[N-i-1]);
         // i までの最小値
        chmin(mn,r[i]);
        rmin[i] = mn;
    }
    // rep(i,N) cout << r[i] << " ";
    // cout << endl;

    mn = INF;
    rep(i,N+1){
        ll l2,r2;
        if(i==0){
            l2 = 0;
            r2 = rmin[N-1-i];
        }
        else if(i==N){
            r2 = 0;
            l2 = lmin[i-1];
        }
        else{
            r2 = rmin[N-1-i];
            l2 = lmin[i-1];
        }
        chmin(mn,r2+l2);
    }
    
    ll ans = sum;
    chmin(ans,sum+mn);
    cout << ans << endl;   
}
