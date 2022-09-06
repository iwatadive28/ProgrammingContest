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
//
int main(){
    string S;
    cin >> S;
    vector<vector<int>> pin(4,vector<int>(7,0));
    bool ans = false;
    rep(i,10){
        if     (i==0) pin[0][3] = (S[i]=='1');
        else if(i==1) pin[1][2] = (S[i]=='1');
        else if(i==2) pin[1][4] = (S[i]=='1');
        else if(i==3) pin[2][1] = (S[i]=='1');
        else if(i==4) pin[2][3] = (S[i]=='1');
        else if(i==5) pin[2][5] = (S[i]=='1');
        else if(i==6) pin[3][0] = (S[i]=='1');
        else if(i==7) pin[3][2] = (S[i]=='1');
        else if(i==8) pin[3][4] = (S[i]=='1');
        else if(i==9) pin[3][6] = (S[i]=='1');
    }
    
    vector<bool> pin_row(7,false);
    rep(j,7){ // 立っているピンが存在するか列ごとに調べる
        bool pn = false;// ピンが立っているか
        rep(i,4) if(pin[i][j]==1) pn = true;
        pin_row[j] = pn;
    }

    for(int j=1;j<6;++j){
        if(pin_row[j]==0){
            bool l = false,r = false;
            rep(i,j)               if(pin_row[i]) l = true;
            for(int i=j+1;i<7;++i) if(pin_row[i]) r = true;
            if(l && r) ans = true;
        } 
    }

    if(pin[0][3]==1) ans = false;    // 1番ピンが立っている

    cout << (ans?"Yes":"No") << endl;
}
