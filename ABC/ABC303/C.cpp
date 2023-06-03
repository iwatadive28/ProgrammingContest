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
    map<char,int> mvx;
    map<char,int> mvy;
    mvx['R'] =  1; mvy['R'] =  0;
    mvx['L'] = -1; mvy['L'] =  0;
    mvx['U'] =  0; mvy['U'] =  1;
    mvx['D'] =  0; mvy['D'] = -1;

    int N,M,H,K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<int,int>> st;
    rep(i,M){
        int x,y;
        cin >> x >> y;
        st.insert({x,y});
    }
    
    int x = 0,y = 0;
    
    bool ans = true;
    rep(i,N){
        x += mvx[S[i]];
        y += mvy[S[i]];
        H--;
        if(H<0){
            ans = false;
            break;
        }
        if(st.count({x,y})){
            if(chmax(H,K)) st.erase({x,y});
        }
        
    }

    cout << (ans?"Yes":"No") << endl;
}
