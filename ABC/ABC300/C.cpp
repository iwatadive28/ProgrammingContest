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
int H,W;

bool ok(int i,int j){
    if(i<0||i>=H) return false;
    if(j<0||j>=W) return false;
    return true;
}

bool test(int i,int j,vector<string> &C,int d){
    for (ll x=-d; x<=d; x+=(2*d)){
        for (ll y=-d; y<=d; y+=(2*d)){
            int s=i+x,t=j+y;
            if(!ok(s,t)) return false;
            if(C[s][t]!='#') return false;
        }
    }
    return true;
}

int main(){
    cin >> H >> W;
    vector<string> C(H);
    rep(i,H) cin >> C[i];

    vector<int> cnt(min(H,W),0);

    for (int i=1; i<H-1; i++){
        for (int j=1; j<W-1; j++){
            // i,j を中心としたバツ印が存在するか
            if(C[i][j]!='#') continue;
            if(test(i,j,C,1)){
                int d=1;
                while(test(i,j,C,d+1)) d++;
                cnt[d-1]++;
            }
        }
    }

    for(auto a:cnt) cout << a << " ";
    cout << endl;
}