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

int main(){
    ll q;
    cin >> q;

    priority_queue<ll,vector<ll>,greater<ll>> que;

    ll sum = 0;
    rep(i,q){
        ll p,x;
        cin >> p;
        if (p == 1){
            cin >> x;
            que.push(x-sum); 
        }
        else if (p == 2){
            cin >> x;
            sum += x;
        }
        else if (p == 3){
            cout << que.top()+sum << endl;
            que.pop();
        }
    }        
}