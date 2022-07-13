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
const string SAT = "satisfiable";

int main(){
    int N;
    cin >> N;
    set<string> S,So;

    rep(i,N){
        string s;
        cin >> s;
        if (s[0] == '!'){
            So.insert(s);
        }else{
            S.insert(s);
        }
    }

    for(auto s : S){
        if(So.count("!"+s)){
            cout << s << endl;
            return 0;
        }
    }
   
    cout << SAT << endl;
}
