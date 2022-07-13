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

int N;
vector<ll> T,K;
vector<vector<ll>> A;
vector<bool> W; // 習得済みの技

ll func(ll x){ //技xを覚えるのに必要な時間
    ll sum = 0;
    sum += T[x];
    rep(i,K[x]){
        if (!W[A[x][i]-1]){ // 未習得の場合
            sum += func(A[x][i]-1);
        }    
    }
    W[x] = true;// 習得済み
    return sum;
}
 
int main() {
    cin >> N;
    T.resize(N);K.resize(N);A.resize(N);
    W.assign(N,false);

    rep(i,N){
        cin >> T[i] >> K[i];
        A[i].resize(K[i]);
        rep(j,K[i]) cin >> A[i][j];
    }

    ll ans = 0;
    ans = func(N-1);
    cout << ans << endl;
}