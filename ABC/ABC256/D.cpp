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
    int N;
    cin >> N;
    vector<pair<int,int>> LR(N);
    rep(i,N){
        int l,r;
        cin >> l >> r;
        LR[i] = make_pair(l,r);
    } 
    sort(LR.begin(),LR.end());
    vector<pair<int,int>> ans;

    ans.push_back(LR[0]); // 最初の和集合
    int cnt = 1;    // 和集合の数
    
    for(int i=1;i<N;i++){
        int l=LR[i].first;
        int r=LR[i].second;

        int sl=ans[cnt-1].first;
        int sr=ans[cnt-1].second;

        if (sr<l){
            ans.push_back(LR[i]);
            cnt++;
        }else{
            if (sr<r){
                ans[cnt-1].second = r;
            }            
        }
    }

    rep(i,cnt){
        cout << ans[i].first << " " << ans[i].second << endl;
    }    
}
