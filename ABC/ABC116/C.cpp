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
    vector<int> h(N);
    rep(i,N) cin >> h[i];

    int ans = 0;
    bool roop = true;
    while(roop){
        bool op = false; // 操作したかどうか？
        rep(i,N){
            if(h[i]!=0){
                op = true;
                h[i]--;
            }
            else if(h[i]==0 && op){
                break;
            }
            if(!op && i==N-1){
                roop = false;
            }
        }
        if (roop) ans++;
    }
    cout << ans << endl;
}
