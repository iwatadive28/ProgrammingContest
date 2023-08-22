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
    int N;
    cin >> N;
    
    int mx=0,mxf=0,mxi=0;
    
    vector<int> f(N),s(N);
    rep(i,N){
        cin >> f[i] >> s[i];
        f[i]--;
        if(chmax(mx,s[i])){
            mxf = f[i];
            mxi = i;
        }
    }

    vector<int> A(N,0);
    rep(i,N){
        if(i==mxi) continue;
        chmax(A[f[i]],s[i]);
    }

    int ans = 0;    
    rep(f,N){
        if(f==mxf) chmax(ans,mx + A[f]/2);
        else chmax(ans,mx + A[f]);
    }
    cout << ans << endl;
}