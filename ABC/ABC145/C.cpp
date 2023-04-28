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
    vector<ll> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    
    vector<int> idx(N);
    rep(i,N) idx[i]=i;
    
    double sum = 0;
    ll cnt = 0;
    do {
        double tmp = 0;
        rep(i,N-1){
            int k  = idx[i];
            int k2 = idx[i+1];
            
            tmp += sqrt((x[k]-x[k2])*(x[k]-x[k2])+(y[k]-y[k2])*(y[k]-y[k2]));
        }
        sum += tmp;
        cnt++;
        // cout << tmp << endl;
    } while (next_permutation(idx.begin(),idx.end()));

    double ave = sum/(double)cnt;
    printf("%.6f\n",ave);
}