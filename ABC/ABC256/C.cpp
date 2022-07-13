#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
ll cnt;
vector<vector<int>> A(3,vector<int>(3));
vector<int> h(3),w(3);

void dfs(int ij){
    int i = ij/3;
    int j = ij%3;
    if(i==3){ // 終了条件
        cnt++;
        return;
    }
    if(i==2){ //i==2 一意に決まる
        int x = w[j]-A[0][j]-A[1][j];
        if(x <= 0) return; // 終了条件, dfs中に条件設ける
        A[i][j] = x;
        dfs(ij+1);

    } else if(j==2){//j==2 一意に決まる
        int x = h[i]-A[i][1]-A[i][0];
        if(x <= 0) return;
        A[i][j]= x;
        dfs(ij+1);

    } else{
        for(int x=1;x<=30;x++){ // 単純に繰り返す
            A[i][j] = x;
            dfs(ij+1);
        }
    }
}

int main(){
    rep(i,3) cin >> h[i];
    rep(i,3) cin >> w[i];
    if( h[0]+h[1]+h[2] != w[0]+w[1]+w[2]){
        cout << 0 << endl;
        return 0;
    }
    
    cnt = 0;
    dfs(0);
    cout << cnt << endl;
}
