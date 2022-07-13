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

    ll cnt = 0;
    for(int i=1;i<=N;++i){
        ll k = i;
        for(int d=2;d*d<=k;d++){
            while (k%(d*d)==0) k/=(d*d);
        }

        for(int j=1;k*j*j<=N;++j){
            cnt++;
        }
    }
    cout << cnt << endl;   
}
