#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    string S;
    cin >> S;
    int N = S.length();
    // 累積和
    vector<vector<int>> sum(N+1, vector<int>(10, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            sum[i+1][j] = sum[i][j] + (S[i]-'0' == j);
        }
    }

    ll ans = 0;
    rep(l,N-1){
        for(ll r=l+1;r<N;r++){
            if((l-r)%2==0) continue;
            
            // 各数字の出現回数の配列を作成
            vector<int> cnt(10,0);
            for (int k = 0; k<10; k++) {
                cnt[k]=sum[r+1][k]-sum[l][k];
            }
            // 出現回数が偶数回？
            bool even = true;
            rep(i,10){
                if(cnt[i]%2==1){
                    even=false;
                    break;
                }
            }
            if(even) ans++;
        }
    }

    cout << ans << endl;
}