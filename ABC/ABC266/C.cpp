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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353;
const double pi = 3.14159265359;
/*
*/
//


// 外積
template<class T> T cross(const pair<T, T> &s, const pair<T, T> &t){
    return s.first*t.second - s.second*t.first;
}
// 内積
template<class T> T dot(const pair<T, T> &s, const pair<T, T> &t){
    return s.first*t.first + s.second*t.second;
}

int main(){
    vector<pair<int,int>> p(4);
    rep(i,4){
        cin >> p[i].first >> p[i].second;
    }

    bool ans = true;
    rep(i,4){
        pair<int,int> oa = {p[i%4].first    -p[(i+1)%4].first, p[i%4].second    -p[(i+1)%4].second};
        pair<int,int> ob = {p[(i+2)%4].first-p[(i+1)%4].first, p[(i+2)%4].second-p[(i+1)%4].second};
        // 外積が負かどうか
        if(cross(ob,oa)<0) ans = false;
        // cout << cross(ob,oa) << endl;
    }

    cout << (ans?"Yes":"No") << endl;
}
