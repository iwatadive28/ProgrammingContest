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
    int N,M,E,Q;
    cin >> N >> M >> E;
    vector<int> U(E),V(E);
    Graph G(N+M);
    rep(i,E) cin >> U[i] >> V[i];

    cin >> Q;
    vector<int> X(Q);
    rep(i,Q) {
        cin >> X[i];
        X[i]--;
    }

    vector<bool> ok(N+1,false);
    rep(i,Q){
        U[X[i]] = -1;
        V[X[i]] = -1;
        rep(i,NM)
        for(int m=N;m<M;++m){

        }

        int ans = 0;
        rep(i,N) if(ok[i]) ans++;
        cout << ans << endl;
    }
        
    cout << endl;   
}
