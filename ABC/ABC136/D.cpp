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
// ランレングス圧縮
vector<pair<char,int>> runlength(string S){
    vector<pair<char,int>> res;
    int cur = 1;
    int n = S.size();
    for(int i=1;i<n;i++){
        if(S[i-1] == S[i]) cur++;
        else{
            res.push_back({S[i-1],cur});
            cur = 1;
        }
    }
    res.push_back({S[n-1],cur});
    return res;
}

int main(){
    string S;
    cin >> S;
    vector<pair<char,int>> compS = runlength(S);
    /*
    for(auto pr:compS){
        cout << pr.first << " " << pr.second << endl;
    }
    // */
    vector<int> ans(S.length(),0);
    int idxR = 0,idxL = -1;
    int n = compS.size();
    for(int i=0;i<n;i+=2){
        int R = compS[i].second;
        int L = compS[i+1].second;
        idxR = idxL + R;
        idxL = idxR + L;

        ans[idxR]   = (R-R/2)+L/2;
        ans[idxR+1] = R/2+(L-L/2);
    }
    
    for(auto a:ans) cout << a << " ";
    cout << endl;
}