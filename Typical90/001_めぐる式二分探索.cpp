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
int N,L,K;
vector<ll> A;
bool solve(ll M){
    ll cnt = 0; // 分割数カウント
    ll pre = 0; // 切り目の座標
    rep(i,N){
        if(A[i]-pre >= M && L-A[i] >= M){
            cnt += 1;
            pre = A[i];
        }
    }
    // K 個以上分割できているか？
    if (cnt >= K) return true;
    else          return false;
}

int main(){
    
    cin >> N >> L >> K;
    A.resize(N);
    rep(i,N) cin >> A[i];
    
    // 答えで二分探索 (めぐる式二分探索法) 
    // https://qiita.com/drken/items/97e37dd6143e33a64c8c
    ll left = -1;
    ll right = L+1;
    while(right - left > 1){
        ll mid = (left+right)/2;
        if(solve(mid) == false) right = mid;
        else left = mid;
    }

    cout << left << endl;
    
}