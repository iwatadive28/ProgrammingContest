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
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<bool>> c(N,vector<bool>(N,false));
    rep(i,M){
        int k;
        cin >> k;
        vector<int> x(k);
        rep(j,k) cin >> x[j];
        
        for(int j=0;j<k-1;++j){
            for(int l=j;l<k;++l){
                c[x[j]-1][x[l]-1] = true;
                c[x[l]-1][x[j]-1] = true;
            }
        }
    }

    bool ans = true;
    for(int j=0;j<N-1;++j){
        for(int l=j;l<N;++l){
            if(!c[j][l]) ans = false;
        }
    }
    
    cout << (ans?"Yes":"No") << endl;
}
