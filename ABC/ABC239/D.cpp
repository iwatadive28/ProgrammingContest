#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//
bool is_prime(int num){
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
    int A,B,C,D;
    cin >> A >> B >> C >> D;

    bool Aoki = true;
    for(int i=A;i<=B;++i){
        bool takahashi = true;
        for(int j=C;j<=D;++j){
            if (is_prime(i+j)){
                takahashi = false;           
            }
        }
        // 最後まで素数にならない場合
        if (takahashi){
            Aoki = false;
            break;
        }
    }

    cout << (Aoki?"Aoki":"Takahashi") << endl; 
    return 0;
    
}