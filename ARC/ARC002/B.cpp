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

int y,m,d;
//             0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12
vector<ll> Mon{0,31,28,31,30,31,30,31,31,30,31,30,31};
void next_day(){
    // うるう年か？
    // （1）の例外として、西暦年号が100で割り切れて400で割り切れない年は平年とする。
    if (m==2){
        if(y%100==0 && y%400!=0) Mon[2] = 28;
        else if (y%4==0) Mon[2] = 29;
        else        Mon[2] = 28;
    }
    // 最終日か？
    if (d==Mon[m]){
        d = 1;
        if (m==12){
            m = 1;
            y++;
        }else{
            m++;
        }
    }else{
        d++;
    }
    return;
}


int main(){
    char ch;
    cin >> y >> ch >> m >> ch >> d;

    while(1){
        if(y%(m*d)==0) break;
        else next_day();
    }

    printf("%04d/%02d/%02d\n",y,m,d);
}
