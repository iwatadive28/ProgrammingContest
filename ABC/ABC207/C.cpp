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

    vector<pair<ll,ll>> lr(N);
    rep(i,N){
        int t;
        ll l,r;
        cin >> t >> l >> r;
        if (t==3) l++;
        else if(r==4) l++;
        lr[i] = make_pair(l,r);
    }
    sort(lr.begin(),lr.end());

    int ans = 0;
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            if(lr[i].second < lr[j].first) continue;
            ans++;
        }
    }
    cout << ans << endl;
}