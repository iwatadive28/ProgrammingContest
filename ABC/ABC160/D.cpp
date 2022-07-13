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
    int N,X,Y;
    cin >> N >> X >> Y;
    vector<int> ans(N,0);

    for(int i=1;i<N;++i){
        for(int j=i+1;j<=N;++j){
            int k = N+1;
            k = min(k,j-i);                  // not use X->Y
            k = min(k,abs(X-i)+abs(Y-j)+1);  // use X->Y
            ans[k]++;
        }
    }
    rep(i,N-1) cout << ans[i+1] << endl;    
}
