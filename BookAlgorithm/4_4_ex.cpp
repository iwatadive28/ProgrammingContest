#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
// 最大公約数を再帰関数で求める
int GCD(int m,int n){
    // Base Case
    if (n==0) return m;
    int res;
    res = GCD(n,m % n);
    return res;
}


int main(){
    cout << GCD(51,15) << endl;
    cout << GCD(15,51) << endl;
    return 0;
}