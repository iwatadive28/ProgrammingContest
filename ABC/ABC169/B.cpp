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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
ull MAX = 1e18;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    sort(a.begin(),a.end());
    ull val = 1;
    rep(i,N) {
        if(a[i]==0){
            cout << 0 << endl;
            return 0;
        }

        if (a[i] <= MAX/val){
            val *= a[i];
        }else{
            cout << -1 << endl;
            return 0;
        }        
    }
    cout << val << endl;
    
}
