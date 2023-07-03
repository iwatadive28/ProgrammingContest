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
    int Ha,Wa;
    cin >> Ha >> Wa;
    vector<string> A(Ha);
    rep(i,Ha) cin >> A[i];

    int Hb,Wb;
    cin >> Hb >> Wb;
    vector<string> B(Hb);
    rep(i,Hb) cin >> B[i];

    int Hx,Wx;
    cin >> Hx >> Wx;
    vector<string> X(Hx);
    rep(i,Hx) cin >> X[i];

    map<pair<int,int>,int> mp;
    vector<vector<char>> C(30,vector<char>(30,'.'));
    rep(i,Hx) rep(j,Wx){
        C[10+i][10+j] = X[i][j];
        if(X[i][j]=='#') mp[{10+i,10+j}] = 1;
    }

    bool fst = true;
    set<pair<int,int>>  sta;
    rep(i,Ha) rep(j,Wa){
        int fst_i,fst_j;
        if(A[i][j]=='#'){
            if(fst){
                fst_i = i,fst_j = j;
                fst = false;
            }
            sta.insert({i-fst_i,j-fst_j});                        
        }
    }
    fst = true;
    set<pair<int,int>>  stb;
    rep(i,Hb) rep(j,Wb){
        int fst_i,fst_j;
        if(B[i][j]=='#'){
            if(fst){
                fst_i = i,fst_j = j;
                fst = false;
            }
            stb.insert({i-fst_i,j-fst_j});                        
        }
    }

    bool ans = false;
    for(auto xa:mp){
        bool oka = true;
        map<pair<int,int>,int> mpa = mp;

        int ia = xa.first.first;
        int ja = xa.first.second;
        for(auto sa:sta){
            int iia = sa.first;
            int jja = sa.second;

            if(C[ia+iia][ja+jja]=='.'){oka = false;break;}
            else mpa[{ia+iia,ja+jja}]--;
        }
        if(!oka) continue;

        for(auto xb:mp){
            bool okb = true;
            map<pair<int,int>,int> mpb = mpa;
            int ib = xb.first.first;
            int jb = xb.first.second;
            for(auto sb:stb){
                
                int iib = sb.first;
                int jjb = sb.second;
                
                if(C[ib+iib][jb+jjb]=='.'){okb = false;break;}
                else mpb[{ib+iib,jb+jjb}]--;
            }
            if(!okb) continue; 
            
            bool ok = true;
            for(auto tt:mpb){
                if(tt.second>0) ok = false;
            }
            if(ok) ans = true;
        }
    }

    cout << (ans?"Yes":"No") << endl;
}