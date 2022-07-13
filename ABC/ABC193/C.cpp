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
bool is_prime(ll num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0) return false; // 素数ではない
    }
    // 素数である
    return true;
}

int main(){
    ll N;
    cin >> N;
    set<ll> st;

    for(ll a=2;a*a<=N;++a){
        for(ll b=2;pow(a,b)<=N;b++){
            st.insert(pow(a,b));
        }
    }
    cout << N-st.size() << endl;
}
