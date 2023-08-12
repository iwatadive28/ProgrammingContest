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
    sort(A.begin(),A.end()); // ,greater<ll>()
    
    ll cnt = N;
    while(cnt!=1){
        // cout << N-cnt+1 << "-" << N << endl;
        ll b = N-cnt;
        for(ll i=b+1;i<N;i++){
            A[i]%=A[b];
            if(A[i]==0) cnt--;
            // cout << i << ":" << A[i] << endl;
        }
        sort(A.begin(),A.end());
    }
    cout << A[N-1] << endl;
    
}
    