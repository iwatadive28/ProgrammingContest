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
int N,T,M;
vector<vector<bool>> hate(10,vector<bool>(10,false));
vector<vector<int>> teams;
int ans;

void dfs(int now){
    if(now==N){
        if(teams.size()==T) ans++;
        return;
    }
    
    // すでにあるチームのnow番目の選手を追加する
    int n = teams.size();
    rep(i,n){
        bool ok = true;
        int m = teams[i].size();
        rep(j,m) if(hate[now][teams[i][j]]){
            ok = false;
            break;
        }
        if(ok){
            teams[i].push_back(now);
            dfs(now+1);
            teams[i].pop_back(); // 元に戻す
        }
    }
    
    // 新しいチームを作る    
    teams.push_back({now});
    dfs(now+1);
    teams.pop_back(); // 元に戻す
}

int main(){
    
    cin >> N >> T >> M;

    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        hate[a][b] = true;
        hate[b][a] = true;
    }
    ans = 0;
    
    dfs(0);
    cout << ans << endl;
}