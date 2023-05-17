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
bool is_atcoder(char c){
    string wd = "atcoder";
    bool res = false;
    for(auto a:wd) if(a==c) res=true;
    return res;
}

int main(){
    string S,T;
    cin >> S >> T;
    int N = S.length();
    
    map<char,int> mpS,mpT;
    rep(i,N){
        mpS[S[i]]++;
        mpT[T[i]]++;
    }
    
    bool ans = true;
    for(char c='a';c<='z';c++){
        // cout << c << ","<< mpS[c] << "," << mpT[c] << endl;
        if(mpS[c]!=mpT[c]){
            if(!is_atcoder(c)){ans = false; break;}
            if(mpS[c]>mpT[c]) mpT['@']-=mpS[c]-mpT[c];
            else              mpS['@']-=mpT[c]-mpS[c];
        }
        if(mpS['@']<0 || mpT['@']<0){ans = false;break;}
    }
    cout << (ans?"Yes":"No") << endl;
}