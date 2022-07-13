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
int main(){
    string  S;
    cin >> S;
    int ans = 0;
    rep(i,10000){
        vector<bool> flag(10,false);
        int x = i;
        rep(i,4){
            flag[x%10] = true;
            x/=10;
        }

        bool flag2 = true;
        rep(i,10){
            if(S[i]=='o' && !flag[i]) flag2 = false; // 'o'なのに存在しない
            if(S[i]=='x' && flag[i])  flag2 = false; // 'x'なのに存在する
        }
        ans += flag2;
    }
    
    cout << ans << endl;   
}
