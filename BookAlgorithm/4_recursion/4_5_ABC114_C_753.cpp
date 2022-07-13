#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
ll cnt = 0;
// 
// N  :Input
// cur:current value
// use:used valses
// cnt:counter
void func(ll N,ll cur,int use){
    
    // Base Case
    if (cur > N) return;
    // 753がすべて1回以上使われていたらカウント
    if (use == 0b111) ++cnt;

    // 現在の値に7or5or3を加える
    func(N, cur*10+7, use|0b100);
    func(N, cur*10+5, use|0b010);
    func(N, cur*10+3, use|0b001);
}

int main(){
    ll N;
    cin >> N;
    func(N,0,0);
    cout << cnt << endl;
}  