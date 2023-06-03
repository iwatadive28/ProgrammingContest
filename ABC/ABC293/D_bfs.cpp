#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    int N,M;
    cin >> N >> M;
    Graph G(N);
    vector<int> deg(N);
    rep(i,M){
        int a, c;
		char b, d;
	    cin >> a >> b >> c >> d;
        a--;c--;        
        G[a].push_back(c);
        G[c].push_back(a);// 無向グラフ
        deg[a]++;deg[c]++;
    }

    // サイクルの個数を求める
    int x=0,y=0;
    vector<bool> used(N,false);
    
    rep(i,N){
        if(used[i]) continue;
        queue<int> que;
        used[i] = true;
        que.push(i);

        bool cycle = true;
        while(!que.empty()){
            int q = que.front();
            que.pop();
            if (deg[q]!=2) cycle=false; // 端が空いてたらサイクルじゃない
            for(int v:G[q]){
                if(used[v]) continue;
                que.push(v);
                used[v]=true;
            }
            //*/
        }
        if(cycle) x++;
        else      y++;
        // */
    }
    // */
    cout << x << " " << y << endl;
}