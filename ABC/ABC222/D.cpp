#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int a[3005];
int b[3005];
int N;
int f[3005][3005];
const int p = 998244353;

int main(){
    
    cin >> N;
    rep(i,N) cin >> a[i];
    rep(i,N) cin >> b[i];

    rep(i,N){
        f[0][i] = 1;
    }
    for (int i = 1;i<=N;i++){
        for (int j=a[i] ; i<=b[i]; j++){
            f[i][j] = f[i-1][j];
        }
        for (int j = 1; j<N; j++){
            (f[i][j] += f[i][j - 1]) %= p;
        }
    }
    
    cout << f[N][N - 1] << endl;     
    
}