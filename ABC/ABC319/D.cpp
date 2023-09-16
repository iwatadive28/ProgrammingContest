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
    int N,M;
    cin >> N >> M;
    vector<ll> L(N,0);
    ll mx = -1;
    ll sum = 0;
    rep(i,N){
        cin >> L[i];
        L[i]++;
        chmax(mx,L[i]);
        sum += L[i];
    } 

    ll lower = mx-1;
    ll upper = sum;

    // 二分探索
    while (lower+1 < upper){
        long mid = (lower+upper)/2;

        int rows = 1;  // 今の行数
        ll length = 0; // 先頭からの文字数
        
        rep(i,N){
            length += L[i];
            if(length>mid){
                rows++;
                length = L[i];
            }
        }

        if (rows > M){
            lower = mid;
        }
        else{
            upper = mid;
        }
    }

    cout << upper -1 << endl;
}