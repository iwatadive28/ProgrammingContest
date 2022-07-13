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
void dfs(int v,vector<bool> &flag, Graph &g){
    if(!flag[v]) return;
    flag[v] = false;
    for(auto &nx:g[v]){
        dfs(nx,flag,g);
    }

}

int main(){
    int N;
    int ans = 0;
    cin >> N;
    vector<int> A(N);
    
    vector<bool> flag(200005,false);
    Graph g(200005);

    for(auto &nx:A){
        cin >> nx;
        if(!flag[nx]) {
            flag[nx] = true;
            ans++;
        }
    }    

    int p=0,q=N-1;
    while(p<q){
        g[A[p]].push_back(A[q]);
        g[A[q]].push_back(A[p]);
        p++;q--;
    }
    
    for(int i=1;i<=200000;i++){
        if(flag[i]){
            ans--;
            dfs(i,flag,g);
        }
    }

    cout << ans << endl;    
}