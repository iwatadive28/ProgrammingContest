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
int main(){
    int N;
    cin >> N;
    vector<string> S(N),T(N);
    rep(i,N) cin >> S[i] >> T[i];
    
    map<string,int> mpS;
    rep(i,N){
        mpS[S[i]] = i+1;
    }

    stack<int> todo;
    map<string,int> mpT;
    rep(i,N){
        if(mpS[T[i]] == 0) todo.push(i+1);
        mpT[T[i]]=i+1;
    }

    int cnt = 0;
    while(!todo.empty()){ // todoが空になるまで探索を行う
        int v = todo.top(); // todoから取り出す
        todo.pop();
        int nv = mpT[S[v-1]];
        if(nv>0){
            todo.push(nv);
        }
        cnt++;
        // cout << S[v-1] << "->" << T[v-1] << endl;
        // cout << cnt << endl;
    }
    cout << (cnt==N?"Yes":"No") << endl;
    //*/
    
}
