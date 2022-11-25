#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    int H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int>> A(H,vector<int>(W));

    // その数値が存在する最大/最小のインデックス
    vector<int> minX(N,H+1);
    vector<int> maxX(N,0);
    vector<int> minY(N,W+1);
    vector<int> maxY(N,0);

    rep(i,H){
        rep(j,W){
            int a;
            cin >> a;
            a -= 1;
            chmin(minX[a],i+1);
            chmax(maxX[a],i+1);
            chmin(minY[a],j+1);
            chmax(maxY[a],j+1);
        }
    }
    
    rep(i,H-h+1){
        rep(j,W-w+1){
            int k  = i+h;
            int l  = j+w;
            int ans= N;
            rep(a,N){
                if (i < minX[a] and maxX[a] <= k and j < minY[a] and maxY[a] <= l) {
                    ans -= 1;
                }
            }
            cout <<  ans << " ";
        }
        cout << endl;
    }
}
