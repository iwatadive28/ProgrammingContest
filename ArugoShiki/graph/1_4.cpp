#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
using Graph = vector<vector<int>>;

int main(){
    // INPUT
    ll N,M,X;
    cin >> N >> M >> X;
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    set<int> st;
    st.insert(X);
    for(auto to:G[X]) st.insert(to); 
    
    
    int cnt = 0;
    for(auto to :G[X]){
        for (auto to2:G[to]){
            if(!st.count(to2)){
                st.insert(to2);
                ++cnt;
            }
        }        
    }
    cout << cnt << endl;
    return 0;
}