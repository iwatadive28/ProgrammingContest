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

// */
bool is_kakko(string s){
    stack<char> st;
    rep(i,s.size()){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    return true;
}

int main(){
    int N;    
    cin >> N;    
    if(N%2==1) return 0;
    
    string s;
    rep(i,N/2){
        s+='(';
        s+=')';
    }
    sort(s.begin(),s.end());

    do {
        if(is_kakko(s)) cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}