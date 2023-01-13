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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
/*
*/
bool is_int(double x){
    if(x==(int)x){
        return true;
    }else{
        return false;
    }
}

pair<ll,ll> solve(){
    ll N;
    cin >> N;
    ll p;
    ll q;

    for (ll i=2;i*i*i<=N;i++){
        ll tp = i*i;
        if(N%tp==0){
            p=i;
            q=N/tp;
            break;
        }
        if(N%i==0){
            double tmp = N/i;
            if(is_int(sqrt(tmp))){
                q=i;
                p=(ll)sqrt(tmp);
            }
        }
    }
    return {p,q};
}

int main(){
    int T;
    cin >> T;
    vector<pair<ll,ll>> ans;
    rep(i,T){
        ans.push_back(solve());
    }

    for(auto p:ans){
        cout << p.first <<" "<< p.second << endl;
    }
}