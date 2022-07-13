#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    int N,K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    
    int ans = 0;
    for(int i=0;i<(1<<N);i++){
        vector<int> sum(26);
        rep(j,N){
            if((i>>j)&1){
                rep(x,S[j].length()){
                    sum[S[j][x]-'a']++;
                }
            }
        }
        int now = 0;
        rep(j,26) if(sum[j]==K) now++;
        ans = max(now,ans);
    }

    cout << ans << endl;
}