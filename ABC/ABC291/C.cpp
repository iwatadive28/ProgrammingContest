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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    pair<ll,ll> P = {0,0};
    set<pair<ll,ll>> st;
    st.insert(P);
    bool ans = false;

    rep(i,N){
        ll x = P.first;
        ll y = P.second;
        if (S[i]=='R')      x+=1;
        else if (S[i]=='L') x-=1;
        else if (S[i]=='U') y+=1;
        else if (S[i]=='D') y-=1;
        
        // cout << i << "," << S[i]<< "," << x << "," << y << endl;
        P = {x,y};
        if(!st.count(P)){
           st.insert(P); 
        }else{            
            ans = true;
            break;
        }
    }
    cout << (ans?"Yes":"No") << endl;
}