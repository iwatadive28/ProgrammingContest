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
    int H,M,h,m;
    cin >> H >> M;
    while(true){
        int h,m;
        h = (H/10)*10 + (M/10);
        m = (H%10)*10 + (M%10);
        if(h<24&&m<60){
            break;
        }        
        M++;
        if(M==60){
            H++;
            M=0;
        }
        if(H==24){
            H=0;
        } 
    }
    cout << H << " " << M << endl;
}
