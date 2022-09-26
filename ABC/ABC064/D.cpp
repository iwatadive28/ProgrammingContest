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
    string S;
    cin >> N >> S;
    
    stack<int> stl; // 左括弧の index を格納するスタック
    stack<int> str; // 左括弧の index を格納するスタック
    rep(i,N){
        if(S[i]=='(') stl.push(i);
        else{
            if(stl.empty()){
                str.push(i);
            }else{
                stl.pop();
            }
        }
    }

    // スタックが空でなかったら左括弧が過剰
    // スタックが空でなかったら右括弧が過剰
    // cout << stl.size() << endl;
    // cout << str.size() << endl;
    string ans = S;
    rep(i,str.size()){
        ans = '(' + ans;
    }

    rep(i,stl.size()){
        ans = ans + ')';
    }
    cout << ans << endl;
}
