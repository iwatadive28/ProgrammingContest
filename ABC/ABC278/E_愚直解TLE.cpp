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
int main(){
    int H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int>> A(H,vector<int>(W));
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B=A;
    
    rep(ii,H-h+1){
        rep(jj,W-w+1){
            set<int> st;
            rep(i,H){
                rep(j,W){
                    // 塗りつぶしていなければinsert
                    if((j<jj||j>=jj+w) || (i<ii||i>=ii+h)){
                        st.insert(A[i][j]);
                        // if(ii==0&&jj==0) cout << A[i][j] << " ";
                    }
                }
            }
            cout <<  st.size() << " ";
        }
        cout << endl;
    }
}
