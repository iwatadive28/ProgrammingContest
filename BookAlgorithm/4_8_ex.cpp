#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
vector<ll> memo;

// フィボナッチ数列を求める FN=FN-1+FN-2;
int fibo(int n){
    printf("fibo(%d)を呼び出しました\n",n);
    
    // Base Case
    if (n<=1) return n;

    int res;
    if (memo[n]!=-1) {
        res = memo[n];
    }else {
        res = fibo(n-1)+fibo(n-2);
        printf("%d項目：%d\n",n,res);
    }
    return res;
}


int main(){
    int N;
    cin >> N;

    memo.assign(N+1,-1);

    cout << fibo(N) << endl;
    return 0;
}