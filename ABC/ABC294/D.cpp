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
    int N,Q;
    cin >> N >> Q;
    
    vector<int> ans;
    set<ll> wait;
    int last = 0;

    rep(i,Q){
        int q;
        cin >> q;
        if(q==1){
            wait.insert(last+1);
            last++;
        }
        else if(q==2){
            int x;
            cin >> x;
            wait.erase(x);
        }
        else if(q==3){
            ans.push_back(*begin(wait));
        }
    }

    for(auto a:ans) cout << a << endl;
}