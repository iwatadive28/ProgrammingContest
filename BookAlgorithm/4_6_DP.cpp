#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    int N,W;
    cin >> N >> W;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    vector<vector<bool>> memo(N+1,vector<bool>(W+1,false));
    // 初期化
    memo[0][0] = true;
    
    // DP
    for(ll i = 0;i<N;++i){
        for(ll w = 0;w<=W;++w){
            if (memo[i][w]){
                memo[i+1][w] = true; // 選ばない場合
                if (w+a[i]<=W) memo[i+1][w+a[i]] = true; // 選ぶ場合
            }
        }
    }
    //Output
    /*
    rep(i,N+1){
        rep(j,W+1){
            cout << memo[i][j] << ','; 
        }
        cout << endl;
    }
    */
    cout << (memo[N][W] ? "Yes":"No") << endl;
    return 0;
}