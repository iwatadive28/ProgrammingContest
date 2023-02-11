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
// 座標圧縮
vector<ll> zahyo(vector<ll> X){
    vector<ll> Y = X;
    sort(Y.begin(),Y.end());

    Y.erase(unique(Y.begin(),Y.end()),Y.end());
        
    // 座標圧縮した結果を求める
    vector<ll> res(X.size());
    for (int i = 0; i < X.size(); ++i) {
        res[i] = lower_bound(Y.begin(), Y.end(), X[i]) - Y.begin();
    }
    return res;
}

int main(){
    ll W,N;
    cin >> W >> N;
    vector<ll> LR1(N*2);
    
    rep(i,N){
        cin >> LR1[2*i] >> LR1[2*i+1];
        LR1[2*i]--;LR1[2*i+1]--;
    }
    // 座標圧縮
    vector<ll> LR = zahyo(LR1);
    ll Wmx = 0;
    rep(i,2*N) chmax(Wmx,LR[i]);

    /*
    rep(i,N) cout << LR[2*i] << ","<< LR[2*i+1] << endl;
    cout << Wmx << endl;
    // */
    
    vector<ll> A(Wmx+1,0);  
    vector<ll> ans(N,0);  
    /*
    cout << "A(Wmx,0)=" ;
    rep(i,Wmx) cout << A[i] << " ";
    cout << endl;
    // */
    rep(i,N){
        ll tmpmx = 0;
        for (ll j=LR[2*i];j<=LR[2*i+1];j++) chmax(tmpmx,A[j]);
        for (ll j=LR[2*i];j<=LR[2*i+1];j++) A[j] = tmpmx+1;
        /*
        cout << i << ":";
        rep(j,N) cout << A[j] << " ";
        cout << endl;
        // */
        ans[i] = tmpmx+1;
    }
    
    rep(i,N) cout << ans[i] << endl;
    // */
}
