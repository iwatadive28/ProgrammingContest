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
    string S;
    cin >> N >> S;
    
    vector<int> ans;
    for(int i=1;i<N;++i){
        int cnt = 0;
        for(int k=0;k<N-i;++k){
            if(S[k]==S[k+i]) break;
            cnt++;
        }
        ans.push_back(cnt);
    }

    for(auto a:ans) cout << a << endl;
}
