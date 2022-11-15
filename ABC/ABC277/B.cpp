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
const ll MOD = 1000000007; //10^9 + 7
/*
*/

string str1 = "HDCS";
string str2 = "A23456789TJQK";

int main(){
    int n;
    cin >> n;
    bool ans = true;
    set<string> st;
    rep(i,n){
        string s;
        cin >> s;
        bool ans1 = false;
        bool ans2 = false;
        bool ans3 = false;

        rep(j,str1.length())if(s[0]==str1[j]) ans1 = true;
        rep(j,str2.length())if(s[1]==str2[j]) ans2 = true;
        if(!st.count(s)){
            st.insert(s);
            ans3 = true;
        }

        if(!(ans1&&ans2&&ans3)){
            ans = false;
        }
    }

    cout << (ans?"Yes":"No") << endl;
}
