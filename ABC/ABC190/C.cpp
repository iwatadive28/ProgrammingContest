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
    int N,M,K;
    cin >> N >> M;
    vector<int> A(M),B(M);
    rep(i,M) cin >> A[i] >> B[i];
    cin >> K;
    vector<int> C(K),D(K);
    rep(i,K) cin >> C[i] >> D[i];
    
    ll ans = 0;
    rep(bit,1<<K){ //2^Kループを回す
        vector<bool> dish(N+1,false); // 各皿上のボールの有無
        rep(i,K){ // i bit目で判断
            if ((bit>>i)&1==1) dish[C[i]] = true;
            else               dish[D[i]] = true;
        }
        
        ll cnt = 0;
        rep(i,M){
            if(dish[A[i]] && dish[B[i]]) cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}
