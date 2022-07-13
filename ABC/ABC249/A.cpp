#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    int A,B,C,D,E,F,X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    
    int Taka=0;
    int Aoki=0;
    int a=A;
    int c=C;
    int d=D;
    int f=F;
    rep(i,X){
        if (a == 0 & c == 0){
            a = A;
            c = C;
        }
        if (a!=0){
            Taka += B;
            a--;
        }
        else{
            c--;
        }

        if (d == 0 & f == 0){
            d = D;
            f = F;
        }
        if (d!=0){
            Aoki += E;
            d--;
        }
        else{
            f--;
        }
    }

    if (Taka>Aoki) cout << "Takahashi" << endl;
    if (Taka<Aoki) cout << "Aoki" << endl;
    if (Taka==Aoki) cout << "Draw" << endl;

}