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

    vector<pair<double,double>> lr;
    rep(i,N){
        int t;
        double l,r;
        cin >> t >> l >> r;
        
        if     (t==2) {r-=0.1;}
        else if(t==3) {l+=0.1;}
        else if(t==4) {l+=0.1;r-=0.1;}
        lr.push_back({l,r});
    }
    
    sort(lr.begin(),lr.end());
    // rep(i,N) cout << lr[i].first << " " << lr[i].second << endl;

    int ans = 0;
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            double ri = lr[i].second;
            double lj = lr[j].first;

            if(ri>=lj) ans++;
        }
    }
    cout << ans << endl;
}