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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/
int N,A,B,C,l[10];
int ans = INF;
int flag[8];

void dfs(int cu) {
    if (cu == N) {
        int a = 0 , b = 0 , c = 0;
        int ca = 0, cb = 0, cc = 0;
        rep(i,N){
            if      (flag[i] == 0){a += l[i]; ca++;}
            else if (flag[i] == 1){b += l[i]; cb++;}
            else if (flag[i] == 2){c += l[i], cc++;}
        }
        if(ca == 0 or cb == 0 or cc == 0) return;
        int cand = (ca-1) * 10 + (cb-1) * 10 + (cc-1) * 10;
        cand += abs(A - a) + abs(B - b) + abs(C - c);
        chmin(ans, cand);
        return;
    }

    rep(i,4){
        flag[cu] = i;
        dfs(cu+1);
    }
}

int main(){
    cin >> N >> A >> B >> C;
    rep(i,N) cin >> l[i];
 
    dfs(0);
    cout << ans << endl;
}