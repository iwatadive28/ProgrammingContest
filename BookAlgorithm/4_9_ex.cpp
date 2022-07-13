#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
vector<ll> memo;

// 部分和問題を再帰関数を使って解く
bool func(int i,int w, const vector<int> &a){
    
    // Base Case
    if (i==0) {
        if (w==0) return true;
        else      return false;
    }

    // (1) a[i-1]を選ばない場合
    if (func(i-1,w,a))        return true;

    // (2) a[i-1]を選ぶ場合
    if (func(i-1,w-a[i-1],a)) return true;

    // どちらもfalseの場合はfalse
    return false;
}


int main(){
    int N,W;
    cin >> N >> W;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    cout << (func(N,W,a) ? "Yes":"No") << endl;
    return 0;
}