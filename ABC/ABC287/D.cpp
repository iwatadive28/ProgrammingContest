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
bool ismatch(char a,char b){
    return a==b || a=='?' || b=='?';
}

int main(){
    string s,t;
    cin >> s >> t;

    vector<int> pre(s.size()+1,false),suf(s.size()+1,false);

    // 先頭の何文字目まで一致するか？
    pre[0] = true;
    rep(i,t.size()){
        if(!ismatch(s[i],t[i])) break;
        pre[i+1] = true;
    }

    // 末尾の何文字目まで一致するか？
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    suf[0] = true;
    rep(i,t.size()){
        if(!ismatch(s[i],t[i])) break;
        suf[i+1] = true;
    }

    // rep(i,s.size()+1) cout << pre[i] << "," << suf[i] << endl;
    
    rep(i,t.size()+1){
        bool ans = false;
        if(pre[i]&&suf[t.size()-i]) ans = true;
        // cout << pre[i] << "," << suf[t.size()-i] << endl;
        cout << (ans?"Yes":"No") << endl;
    }
}
