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
    string S;
    int K;
    cin >> S >> K;

    int N = S.length();
    vector<int> cnt(N);
    cnt[0]=(S[0]=='.');

    for(int i=1;i<N;++i){
        if(S[i]=='.') cnt[i]= cnt[i-1]+1;
        else          cnt[i]= cnt[i-1];
    }

    ll ans = 0;
    ll r = 0;
    // 尺取り法
    rep(l,N){
        while(r<N && cnt[r]-cnt[l-1] <= K){
            r = r+1;
        }
        ans = max(ans,r-l);
    }
    
    cout << ans << endl;
}