#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
vector<vector<int>> memo;

// 部分和問題を再帰関数を使って解く
bool func(int i,int w, const vector<int> &a){
    
    // Base Case
    if (i==0) {
        if (w==0) return true;
        else      return false;
    }
    // メモをチェック
    if (memo[i][w]!=-1) return memo[i][w];

    // (1) a[i-1]を選ばない場合
    if (func(i-1,w,a))        return memo[i][w] = 1;

    // (2) a[i-1]を選ぶ場合
    if (func(i-1,w-a[i-1],a)) return memo[i][w] = 1;

    // どちらもfalseの場合はfalse
    return memo[i][w] = 0;
}


int main(){
    int N,W;
    cin >> N >> W;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    memo.assign(N+1,vector<int>(W+1,-1));

    cout << (func(N,W,a) ? "Yes":"No") << endl;
    rep(i,N+1){
        rep(j,W+1){
            cout << memo[i][j] << ','; 
        }
        cout << endl;
    }
    return 0;
}