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
string dec2oct(int x){
    string oct;
    while(x>7){
        int tmp = x%8;
        oct = to_string(tmp) + oct;
        x /= 8;
    }
    oct = to_string(x) + oct;
    return oct;
}

int main(){
    int N;
    cin >> N;
    // cout << dec2oct(N) << endl;
    
    int cnt = 0;
    for(int i=1;i<=N;i++){
        bool b7 = false;
        string s10 = to_string(i);
        rep(j,s10.size()){
            if (s10[j]=='7') {
                b7 = true;
                break;
            }
        }
        if(b7){
            cnt++;
            continue;
        }

        string s8 = dec2oct(i);
        rep(j,s8.size()){
            if (s8[j]=='7') {
                b7 = true;
                break;
            }
        }
        if(b7){
            cnt++;
        }

    }

    // 10->8
    cout << N-cnt << endl;
}
