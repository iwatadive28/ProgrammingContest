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

int main(){
    double a,b;
    cin >> a >> b;
    
    double d = sqrt(pow(a,2)+pow(b,2));
    double ra = a/d;
    double rb = b/d;

    printf("%.12f %.12f\n",ra,rb);

}