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
    int N,Q;
    cin >> N;
    // map で計算するとTLE
    vector<vector<int>> vec(N+1); // 1次元のみサイズ指定
    rep(i,N){
        int a;
        cin >> a;
        vec[a].push_back(i+1);
    }

    cin >> Q;    
    // O(Q(2*logN))
    rep(i,Q){
        int L,R,X;
        cin >> L >> R >> X;
        int lower = lower_bound(vec[X].begin(),vec[X].end(),L)   - vec[X].begin(); 
        int upper = lower_bound(vec[X].begin(),vec[X].end(),R+1) - vec[X].begin(); 
        cout << upper - lower << endl;
    } 
       
}