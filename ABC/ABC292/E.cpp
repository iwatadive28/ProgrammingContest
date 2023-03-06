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
    int N,M;
    cin >> N >> M;
    Graph G(N+1);
    rep(i,M){
       int a,b;
       cin >> a >> b;
       a--;b--;
       G[a].push_back(b);
    }
    
    ll ans = 0;
    rep(i,N){
        // BFS;
        vector<bool> f(N,false);
        f[i] = true;
        queue<ll> Q;
        Q.push(i);

        while(!Q.empty()){
            ll v = Q.front();
            Q.pop();
            for(auto nv:G[v]){
                if(f[nv]) continue;
                f[nv] = true;
                Q.push(nv);
                ans++;
            }
        }
    }
    ans -= M;
    cout << ans << endl;
    // */
}