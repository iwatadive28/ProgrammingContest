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
    vector<pair<int,int>> x;
    rep(i,N){
        int a,b;
        cin >> a >> b;
        x.push_back({a,1});
        x.push_back({a+b,-1});
    }
    sort(x.begin(),x.end());
    
    int cnt = 0;
    vector<int> ans(N+1);
    
    rep(i,x.size()-1){
        cnt += x[i].second;
        ans[cnt] += (x[i+1].first - x[i].first); 
    }

    rep(i,N) cout << ans[i+1] << " ";
    cout << endl;
}
