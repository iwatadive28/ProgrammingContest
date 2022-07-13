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
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    int N;
    cin >> N;
    
    // 0~9が何番目に出てくるかカウントする
    vector<vector<int>> A(10,vector<int>(N));
    rep(i,N){
        string S;
        cin >> S;
        rep(j,10){
            int s = ctoi(S[j]);
            A[s][i] = j;
        }
    }

    // 0~9までそろえる時間を計算する
    // 出てくる順番に重複があれば10を足す
    int ans = 10000;
    rep(j,10){
        map<int,int> mp;
        int mx  = 0;
        rep(i,N){
            int n = A[j][i];
            if (mp.find(n) == mp.end()){
                mp[n] = 0;
            }else{
                mp[n]++;
            }            
            mx = max(mx,n+10*mp[n]);
        }
        ans = min(mx,ans);
    }

    cout << ans << endl;
}