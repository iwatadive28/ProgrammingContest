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
const double pi = 3.14159265359;
/*
//*/
double mypow2(double a){return a*a;}

int main(){
    ll T,L,X,Y,Q;
    cin >> T >> L >> X >> Y >> Q;

    double r = (double)L/2;
    vector<double> ans;
   
    rep(i,Q){
        ll E;
        cin >> E;
        double theta = (double)(E%T)/T * 2*pi;
        double y = -r*sin(theta);
        double z = -r*cos(theta)+r;
        double l = sqrt(mypow2(X)+mypow2(Y-y)+mypow2(z));
        double ang = 90-acos(z/l)*180/pi;
        ans.push_back(ang);
        // cout << theta << "," << y << "," << z << "," << ang << endl;
    }

    for(auto a:ans){
        printf("%.8f\n",a);
    }    
}   