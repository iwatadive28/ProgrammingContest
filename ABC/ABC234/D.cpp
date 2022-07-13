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
    vector<int> P(N);
    rep(i,N) cin >> P[i];

    // 優先度付きキュー,デフォルトでは最大値を取り出す
    priority_queue<int,vector<int>,greater<int> > que;
    rep(i,K) que.push(P[i]);
    // 最小値を出力
    cout << que.top() << endl;

    // O((n-k)) // que:O(logk)
    for(int i=K;i<N;++i){
        if (que.top()<P[i]){
            que.pop();
            que.push(P[i]);
        }
        // 最小値を出力
        cout << que.top() << endl;    
    }
}