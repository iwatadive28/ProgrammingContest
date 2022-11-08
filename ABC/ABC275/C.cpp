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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353; //998244353
/*
*/
vector<string> s(9);

ll dist2(int x1,int y1,int x2,int y2){
    int res = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return res;
}

int is_square(int i,int j,int k,int l){
    
    vector<int> x(4),y(4);
    x[0]=i%9,y[0]=i/9;
    x[1]=j%9,y[1]=j/9;
    x[2]=k%9,y[2]=k/9;
    x[3]=l%9,y[3]=l/9;

    if(s[x[0]][y[0]]!='#' ||
       s[x[1]][y[1]]!='#' ||
       s[x[2]][y[2]]!='#' || 
       s[x[3]][y[3]]!='#'){
        return false;
    }

    vector<ll> d(6);
    int cnt = 0;
    for(int ii=0;ii<3;++ii){
        for(int jj=ii+1;jj<4;++jj){
            d[cnt] = dist2(x[ii],y[ii],x[jj],y[jj]);
            cnt++;
        }
    }

    sort(d.begin(),d.end());
    bool res = false;
    if(d[0]==d[1] && 
       d[1]==d[2] &&
       d[2]==d[3] &&
       d[4]==d[5] &&
       d[4] == 2*d[0]){
        res = true;
       }

    return res;
}

int main(){
    
    rep(i,9) cin >> s[i];

    int ans = 0;
    for(int i=0;i<81;++i){
        for(int j=i+1;j<81;++j){
            for(int k=j+1;k<81;++k){
                for(int l=k+1;l<81;++l){
                    if (is_square(i,j,k,l)) ans++;
                }
            }
        }
    }

    
    cout << ans << endl;
}
