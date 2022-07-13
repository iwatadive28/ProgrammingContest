#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int n,n2;
vector<vector<int>> a;
int ans; // グローバル変数はゼロで初期化
void dfs(vector<bool> s, int x){ //( 集合,XOR )
    int si = -1;
    rep(i,n2) if (!s[i]) { si = i ; break;} // 残っているもので先頭にあるもの
    
    if (si == -1){ // 全部使っていたら
        ans = max(ans,x); // XORの合計と比較して大きいほうを残す
        // cout << ans << endl;
        return;
    }

    s[si] = true;
    rep(i,n2) if (!s[i] && si != i){ // まだ使ってない & siと異なるi
        s[i] = true; // 使用済みにする
        dfs(s,x^a[si][i]);
        s[i] = false; // 帰ってきたら元に戻しておく
    }
}


int main(){
    cin >> n;
    n2 = n*2;
    a = vector<vector<int>>(n2,vector<int>(n2));
    
    rep(i,n2){
        for (int j=i+1; j<n2 ;++j){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    } 

    vector<bool> s(n2);
    dfs(s,0); 

    cout << ans << endl;
    return 0;
}