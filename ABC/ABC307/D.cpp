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
    int N;
    string S;
    cin >> N >> S;

    stack<char> st; // (のidxを格納する
    int cnt = 0; // (をカウント

    rep(i,S.length()){
        st.push(S[i]);
        if(S[i]=='('){            
            cnt++;
        }else if(S[i]==')' && cnt>0){
            while(true){
                char t = st.top();
                st.pop();
                if(t=='('){
                    cnt--;
                    break;
                }
            }            
        }
    }

    string ans ="";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}