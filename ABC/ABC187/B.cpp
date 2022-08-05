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
    int N;
    cin >> N;
    vector<int> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    
    int ans = 0;
    rep(i,N-1){
        for(int j=i+1;j<N;++j){
            double a = ((double)y[j]-(double)y[i])/((double)x[j]-(double)x[i]);
            if(-1<=a&&a<=1) ans++;
        }
    }
    
    cout << ans << endl;
}
