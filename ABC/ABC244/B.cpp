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

int main(){
    int N;
    string T;
    cin >> N;
    cin >> T;

    vector<int> xd = {1, 0,-1, 0};
    vector<int> yd = {0,-1, 0, 1};

    int x = 0,y = 0;
    int k = 0; // 0~3
    rep(i,N){
        if (T[i] == 'S'){
            x += xd[k]*1;
            y += yd[k]*1;            
        }else{
            k = (k+1)%4;
        }
    }
    cout << x << " " << y << endl;
}