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
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> pr(N);
    vector<vector<bool>>  F(N,vector<bool>(M,false));

    rep(i,N){
        int p,c;
        cin >> p >> c;
        pr[i]={p,(int)i};
        rep(j,c){
            int f;
            cin >> f;
            F[i][f] = true;
        }
    }
    sort(pr.begin(),pr.end()); // ,greater<ll>()
    reverse(pr.begin(),pr.end());

    bool ans = false;
    rep(i,N){
        int ii = pr[i].second;
        int pi = pr[i].first;
        for(int j=i+1;j<N;++j){
            int jj = pr[j].second;
            int pj = pr[j].first;
            
            bool tmp2 = true;
            rep(k,M){
                if(F[ii][k] && !F[jj][k]) tmp2 = false;
            }
            
            bool tmp3 = false;
            if(pi>pj) tmp3 = true;
            else{
                rep(k,M){
                    if(!F[ii][k] && F[jj][k]) tmp3 = true;
                }
            }
                
            if(tmp2 && tmp3) ans = true;
        }
    }

    cout << (ans?"Yes":"No") << endl;
}