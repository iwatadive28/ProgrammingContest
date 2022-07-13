#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//
int N;
vector<string> S(1010);

// x,yから6連続するか判定する
// 領域外なら0を返す
int cnt6_x(int x,int y){
    int cnt = 0;
    rep(i,6){
        if (y+i >= N) return 0;
        if (S[x][y+i]=='#') ++cnt;
    }
    return cnt;
}
int cnt6_y(int x,int y){
    int cnt = 0;
    rep(i,6){
        if (x+i >= N) return 0;
        if (S[x+i][y]=='#') ++cnt;
    }
    return cnt;
}
int cnt6_s1(int x,int y){
    int cnt = 0;
    rep(i,6){
        if (x+i >= N || y+i >= N) return 0;
        if (S[x+i][y+i]=='#') ++cnt;
    }   
    return cnt;
}
int cnt6_s2(int x,int y){
    int cnt = 0;
    rep(i,6){
        if (x-i < 0 || y+i >= N) return 0;
        if (S[x-i][y+i]=='#') ++cnt;
    }
    return cnt;
}

int main(){
    
    cin >> N;
    rep(i,N) cin >> S[i];

    // cout << cnt6_s2(3,5) << endl;
    
    bool ans = false;
    // 任意の(i,j)マスから６マス中、#が何個あるかカウント。
    // 4以上ならTureを返す
    rep(i,N){
        rep(j,N){
            if (cnt6_x(i,j) >= 4 || cnt6_y(i,j) >= 4 ||cnt6_s1(i,j) >= 4 || cnt6_s2(i,j) >= 4 ){
                ans = true;
                break;
            }
        }
    }    
    cout << (ans?"Yes":"No") << endl;
    return 0;
    
}