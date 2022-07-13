#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int ope_2(int x){
    string s = to_string(x);
    int len = s.size();
    rotate(s.begin(),s.begin()+(len-1),s.end());
    int ret = stoi(s);
    return ret;
}

int main(){
    int n,a;
    const int MX  = 1000000;
    const int INF = 1001001001; 
    vector<int> dist(MX,INF);
    queue<int> q;

    auto push =[&](int v,int d){
        if (dist[v] != INF) return;
        dist[v] = d;
        q.push(v);
    };

    cin >> a >> n;
    push(1,0);
    while (!q.empty()){
        int v = q.front(); q.pop();
        int d = dist[v];
        // 操作1
        if (ll(v)*a <MX){
            push(v*a,d+1);
        }
        // 操作2
        if (v >= 10 && v%10 != 0){
            int u = ope_2(v);
            push(u,d+1);            
        }
    }

    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
    
    return 0;
}