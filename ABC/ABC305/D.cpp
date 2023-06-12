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
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    ll Q;
    cin >> Q;
    vector<ll> l(Q),r(Q);
    rep(i,Q) cin >> l[i] >> r[i];

    // 累積和
    vector<ll> slp(N);
    slp[0] = 0;
    for(int i=1;i<N;i++){
        if(i%2==0) slp[i] = slp[i-1] + (A[i]-A[i-1]);
        else       slp[i] = slp[i-1];
    }
    // for(auto a:slp) cout << a << endl;
    
    vector<ll> ans(Q);
    rep(i,Q){
        // x[i]以上の範囲で最小のインデックスを返す
        ll itl = lower_bound(A.begin(),A.end(),l[i]) - A.begin();
        ll itr = lower_bound(A.begin(),A.end(),r[i]) - A.begin();
        
        ll st,ed;
        if(itl%2==0)   st = slp[itl]+(l[i]-A[itl]);
        else           st = slp[itl];

        if(itr%2==0)   ed = slp[itr]-(A[itr]-r[i]);
        else           ed = slp[itr];
        
        // cout << itl <<" " << itr << " ";
        // cout << st << " " << ed << endl;
        
        ans[i] = (ed-st);
    }
    
    for(auto a:ans) cout << a << endl;
    
}