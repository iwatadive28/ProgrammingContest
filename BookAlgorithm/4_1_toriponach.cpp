#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
vector<ll> memo;
int cnt = 0;

// トリポナッチ数列を再帰関数を使って解く
int fT(int i){
    
    // Base Case
    if (i==0) return 0;
    else if(i==1) return 0;
    else if(i==2) return 1;
    
    // Ｔ
    cnt++;
    return fT(i-1)+fT(i-2)+fT(i-3);
}


int main(){
    int N;
    cin >> N;
    rep(i,N){
        cout <<  "T("<< i << ")=" << fT(i) << ", cnt = ";
        cout << cnt << endl;
        cnt = 0;
    }
    cout << cnt << endl;
    return 0;
}  