#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    vector<pair<int,int>> q;
    int cnt = 0;
    rep(i,N){
        int val = a[i]; 
        
        // 今何個目かカウントする
        // 前の数と一致していたらインクリメント
        int sq;
        if (cnt==0) sq = 1;
        else if (q[cnt-1].first == val) sq = q[cnt-1].second + 1;
        else  sq = 1;
        
        if (sq == val){
            // 条件を満たしていたら消す
            rep(j,val-1) q.erase(q.begin()+cnt-1-j);
            // q.erase(q.begin()+cnt-2-val,q.begin()+cnt-1);
        }else{
           // 挿入する
           q.push_back (make_pair(val,sq)) ;
        }
        rep(k,q.size()) cout << q[k].first << "," << q[k].second << endl;
        cout << q.size() << endl;
        cnt = q.size();
    }
}