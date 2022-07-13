#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int cnt_yakusu(int x){
    int cnt_yakusu = 0;
    for(int i=0;i<x;i++){
        if (x%(i+1) == 0){
            cnt_yakusu ++;
        }
    }
    return cnt_yakusu;
}

int N,K;

int main() {
	cin >> N >> K;
    
    int cnt = 0;
    rep(i,N){
        // cout << i+1 << ","<< cnt_yakusu(i+1) << endl;
        if (cnt_yakusu(i+1) == K){
            cnt++;
        }
    }    
    cout << cnt << endl;
    return 0;
}