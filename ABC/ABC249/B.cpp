#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    string S;
    cin >> S;
    bool diff = true;
    bool komoji = false;
    bool omoji  = false;

    set<char> st;
    rep(i,S.length()){
        // 同じ文字があるか？
        if(!st.count(S[i])){
            st.insert(S[i]);
        }else{
            diff = false;break;
        }
        // 大文字か、小文字か？
        if ('A'<=S[i] & S[i]<='Z') omoji = true;
        if ('a'<=S[i] & S[i]<='z') komoji  = true; 
    }
    // cout << "diff,omoji,komoji=" << diff << omoji << komoji << endl;

    bool ans = diff & komoji & omoji;

    cout << (ans?"Yes":"No") << endl;
}