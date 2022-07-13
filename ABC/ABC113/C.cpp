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
    int N,M;
    cin >> N >> M;
    vector<int> P(N),Y(N);
    vector<pair<int,pair<int,int>>> ypi(M);
    rep(i,M){
        int p,y;
        cin >> p >> y;
        ypi[i] = {y,{p,i}};
    }
    sort(ypi.begin(),ypi.end());

    vector<int> cnt(N+1,0);
    vector<pair<int,pair<int,int>>> ipc(M);
    rep(i,M){
        pair<int,int>& pi = ypi[i].second;
        int p  = pi.first;
        int ii = pi.second;
        cnt[p]++;
        ipc[i] = {ii,{p,cnt[p]}};
        // printf("%6d,%6d,%6d\n",ii,p,cnt[p]);
    }

    sort(ipc.begin(),ipc.end());
    rep(i,M){
        int p = ipc[i].second.first;
        int c = ipc[i].second.second;
        printf("%06d%06d\n",p,c);
    }   

}
