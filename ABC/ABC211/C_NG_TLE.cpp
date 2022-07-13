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
ll ans;
vector<vector<ll>> a(8);

void dfs(int cur,int idx){
    // 最終条件
    if (cur == 8){
        ans++;
        ans%=MOD;
        return;
    }

    int cl = lower_bound(a[cur].begin(),a[cur].end(),idx)-a[cur].begin();
    for(int i = cl;i<a[cur].size();++i){
        dfs(cur+1,a[cur][i]);
    }
}

int main(){
    string s;
    cin >> s;
    
    rep(i,s.size()){
        if      (s[i]=='c') a[0].push_back(i);
        else if (s[i]=='h') a[1].push_back(i);
        else if (s[i]=='o') a[2].push_back(i);
        else if (s[i]=='k') a[3].push_back(i);
        else if (s[i]=='u') a[4].push_back(i);
        else if (s[i]=='d') a[5].push_back(i);
        else if (s[i]=='a') a[6].push_back(i);
        else if (s[i]=='i') a[7].push_back(i);
    }
    rep(i,8) a[i].push_back(INF);
    dfs(0,-1);

    cout << ans << endl;
}