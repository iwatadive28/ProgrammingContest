#include <iostream>
#include <bits/stdc++.h>
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
    int N,Q;
    cin >> N >> Q;
    
    vector<ll> pos(N+1); // ボールiのポジション
    vector<ll> ans(N+1); // ポジションiのボール番号

    rep(i,N){
        pos[i+1] = i+1;
        ans[i+1] = i+1;
    }
    
    rep(i,Q){
        ll x;
        cin >> x;
        x;
        ll pos1,pos2;
        if (pos[x] == N){
            pos1 = pos[x];
            pos2 = pos1-1;
        }
        else{
            pos1 = pos[x];
            pos2 = pos1+1;
        }
        ll num1 = ans[pos1];
        ll num2 = ans[pos2];
        
        swap(pos[num1],pos[num2]);
        swap(ans[pos1],ans[pos2]);
    }

    rep(i,N){
        cout << ans[i+1] << " ";
    }
    cout << endl;
    
}