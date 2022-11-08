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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
double mypow2(double a){return a*a;}
double pi = 3.141592653589;
int main(){
    double A,B,H,M;
    cin >> A >> B >> H >> M;
    
    double theta_A,theta_B;
    theta_A = (H+M/60)*pi/6;
    theta_B = M*pi/30;

    // cout << theta_A << "," << theta_B << endl;

    double xa,ya,xb,yb;
    xa = A*sin(theta_A);
    ya = A*cos(theta_A);
    xb = B*sin(theta_B);
    yb = B*cos(theta_B);

    // cout << xa << "," << ya << endl;
    // cout << xb << "," << yb << endl;
    
    double ans = sqrt(mypow2(xa-xb)+mypow2(ya-yb));
    printf("%.10f\n",ans);
}