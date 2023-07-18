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
string NP = "Not Prime\n";
string P  = "Prime\n";
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
// Nを10進表記した時の1の位が偶数でも5でもなく
bool is_ppoi1(ll x){
    if (x%10 == 5) return false;
    else if ((x%10)%2==0) return false;
    else return true;
}
// 各桁の和が3で割り切れない
bool is_ppoi2(ll x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x /= 10;
    }

    if(sum%3 == 0) return false;
    else return true;
}

bool is_ppoi(ll x){
    if (x<2) return false;
    if (is_ppoi1(x) && is_ppoi2(x)) return true;
    else return false;
}

int main(){
    ll N;
    cin >> N;
    
    if(is_prime(N) || is_ppoi(N))  cout << P;
    else cout << NP;
}
