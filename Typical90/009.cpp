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
//*/
const double pi = 3.14159265358979;

double getangle(double x,double y) {
	// 点 G の偏角を求める
	if (y >= 0.0) {
		double I = x / sqrt(x*x + y*y);
		double kaku = acos(I) * 180.0 / pi;
		return kaku;
	}
	else {
		double I = x / sqrt(x*x + y*y);
		double kaku = acos(I) * 180.0 / pi;
		return 360.0 - kaku;
	}
}

double getangle2(double t1,double t2){
    double res = abs(t1-t2);
    if(res>=180.0) res = 360.0-res;
    return res;
}

int main(){
    int N;
    cin >> N;
    vector<ll> x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];

    double ans = -1;
    rep(i,N){
        ll x0 = x[i];
        ll y0 = y[i];
        // 真ん中決め打ち + 偏角ソート
        vector<double> angle;
        rep(j,N){
            if(i==j) continue;
            // double tmp = atan2((double)(y[j]-y0),(double)(x[j]-x0))*180.0/pi;
            // double tmp = atan2l((double)(y[j]-y0),(double)(x[j]-x0))*180.0/pi;
            // if(tmp<0) tmp+=360.0;
            double tmp = getangle((double)(y[j]-y0),(double)(x[j]-x0));
            angle.push_back(tmp);
            // printf("i=%d,j=%d,%f\n",(int)i,(int)j,tmp);
        }
        sort(angle.begin(),angle.end());
        for(double t1:angle){
            // 二分探索で最も角度の大きくなる点を2点に絞り込む
            double key = t1+180.0;
            if(key>=360) key-=360.0;
            int p1 = lower_bound(angle.begin(),angle.end(),key) - angle.begin();
            
            int c1 = p1 % angle.size();
            int c2 = (p1+angle.size()-1) % angle.size(); // 正の整数 mod
            
            double ang1 = getangle2(t1,angle[c1]);
            double ang2 = getangle2(t1,angle[c2]);
            double tmp = max(ang1,ang2);
            if(chmax(ans,tmp)){
                // printf("i=%d,t1=%f,t2=%f,ans=%f\n",(int)i,t1,angle[p1],ans);            
            }
        }
    }
    printf("%.8f\n",ans);
}   