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
const ll MOD = 1000000007; //10^9 + 7
/*
*/

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin >> S[i];

    int ans = 0;
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            int a = M;
            rep(k,M){
                if(S[i][k]=='o' || S[j][k]=='o') a--;
            }
            if(a==0) ans++;
        }
    }
    cout << ans << endl;
}