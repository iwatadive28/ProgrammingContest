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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

string snuke = "snuke";
vector<int> dx = {-1,-1,-1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1,-1, 1,-1, 0, 1};

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];

    vector<pair<int,int>> ans(5);
    bool is_snuke = false;
    rep(i,H){
        rep(j,W){            
            rep(d,8){
                int x=i,y=j;
                rep(k,5){
                    if(x<0||x>=H||y<0||y>=W) break;
                    if(S[x][y]==snuke[k]){
                        ans[k]={x+1,y+1};
                        x += dx[d];
                        y += dy[d];
                        if(k==4){
                            is_snuke = true;
                            break;
                        }
                    }else{
                        break;
                    }                    
                }
                if(is_snuke) break;
            }            
            if(is_snuke) break;
        }
        if(is_snuke) break;
    }

    for(auto rc:ans){
        cout << rc.first << " " << rc.second << endl;
    }
}