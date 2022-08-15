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
    ll N;
    cin >> N;
    vector<int> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];

    bool ans = false;
    // O(10^6)
    for(int i=0;i<N-2;++i){
        for(int j=i+1;j<N-1;++j){
            for(int k=j+1;k<N;++k){
                int dx1 = x[i]-x[j];
                int dy1 = y[i]-y[j];
                int dx2 = x[j]-x[k];
                int dy2 = y[j]-y[k];
                if(dx2*dy1==dx1*dy2) ans = true;
            }
        }
    }
    cout << (ans?"Yes":"No") << endl;
}
