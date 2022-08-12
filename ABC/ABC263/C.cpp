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
void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

vector<int> a(10,999999);
vector<vector<int>> aa(0,vector<int>(10));

int main(){
    int N,M;
    cin >> N >> M;
    //mCn
    //vector<vector<int>> aa(0,vector<int>(N));
    foreach_comb(M, N, [](int *indexes) {
        rep(i,10) a[i] = indexes[i]+1;
        aa.push_back(a);
    });

    vector<int> b(N);
    vector<vector<int>> bb(0,vector<int>(N));
    rep(i,aa.size()){
        rep(j,N){
            b[j] = aa[i][j];
        }
        sort(b.begin(),b.end());
        bb.push_back(b);
    }

    sort(bb.begin(),bb.end());

    rep(i,bb.size()){
        rep(j,N){
            cout << bb[i][j] << " ";
        }
        cout << endl;        
    }    
}
