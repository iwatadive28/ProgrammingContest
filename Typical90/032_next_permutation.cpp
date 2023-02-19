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
    vector<vector<ll>>  A(N,vector<ll>(N,0));
    rep(i,N) rep(j,N) cin >> A[i][j];
    int M;
    cin >> M;
    vector<vector<bool>>  ng(N,vector<bool>(N,false));
    rep(i,M){
        int x,y;
        cin >> x >> y;
        x--;y--;
        ng[x][y] = true;
        ng[y][x] = true;        
    }

    // 小さい制約は順列全探索
    vector<ll> a(N);
    rep(i,N) a[i]=i;
    ll ans = INF;
    do {
        ll tmp = A[a[0]][0];
        bool ok = true;
        rep(i,N-1){
            if(ng[a[i]][a[i+1]]){
                ok = false;
                break;
            }
            else tmp += A[a[i+1]][i+1];
        }
        if(ok) chmin(ans,tmp);
    } while (next_permutation(a.begin(), a.end()));

    cout << ((ans==INF)?-1:ans) << endl;
}