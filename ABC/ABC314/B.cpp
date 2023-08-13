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
    int N;
    cin >> N;
    map<int,vector<int>> mp;
    vector<vector<int>> A(N,vector<int>(0));
    rep(i,N){
        int c;
        cin >> c;
        rep(j,c){
            int a;
            cin >> a;
            A[i].push_back(a);
            mp[a].push_back(i);
        }
    }
    int X;
    cin >> X;
    
    vector<int> vc = mp[X];
    int mnsz = 1000;
    for(auto i:vc){
        int a = A[i].size();
        chmin(mnsz,a);
    }
    
    vector<int> ans;
    for(auto i:vc){
        if(A[i].size()==mnsz){
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto a:ans) cout << a << " ";
    cout << endl;

}