#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
/*
*/
//
void output(vector<ll> a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
    return;
}

// マージソート
int main(){
    // INPUT
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    vector<ll> L,R;
    ll x = N/2;
    rep(i,N){
        // 1. A[0],A[1],⋯,A[X−1] をこの順に配列 L に格納する
        if (i<x){
            L.push_back(a[i]);
        }
        // 2. A[X],A[X+2],⋯,A[N−1] をこの順に配列 R に格納する。
        else{
            R.push_back(a[i]);
        }
    }
    // 3. L,R を再帰的にソートする。要素数が 1 以下の場合は何も行わない。
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());

    // 4. R を逆順に並び替え、 L の最後尾に結合する。
    reverse(R.begin(),R.end());
    L.insert(L.end(),R.begin(),R.end());
    
    // 5.空配列 B を用意し、 L が空になるまで以下を繰り返し行う。
    
    vector<ll> B;
    ll l=0,r=N-1;    
    while(l<=r){
        // (1) Lの先頭の要素を e_first、末尾の要素を e_lastおく
        ll e_first = L[l];
        ll e_last  = L[r];
        // (2) e_first<=e_lastならばe_firstの値をBの末尾に追加し、e_firstを削除する
        if (e_first <= e_last){
            B.push_back(e_first);
            ++l;
        }
        // (3) e_first>e_lastならばe_lastの値をBの末尾に追加し、e_firstを削除する
        else if (e_first > e_last){
            B.push_back(e_last);
            --r;
        }
    }
    
    // 6. 配列 B の値を出力する。
    output(B);
    
    return 0;
}