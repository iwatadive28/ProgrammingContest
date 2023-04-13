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

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> back(N+1,-1);
    vector<int> frnt(N+1,-1);
    vector<vector<int>> ans;
    vector<int> M;
    rep(i,Q){
        int q;
        cin >> q;

        if(q==1){
            int x,y;
            cin >> x >> y;
            back[x]=y;
            frnt[y]=x;
        }
        else if(q==2){
            int x,y;
            cin >> x >> y;
            back[x] = -1;
            frnt[y] = -1;
        }
        else if(q==3){
            int x;
            cin >> x;
            int m = 0;
            vector<int> out;
            while(frnt[x]!=-1){
                x=frnt[x];
            }
            while(true){
                m++;
                out.push_back(x);
                if(back[x]==-1) break;
                x=back[x];
            }
            M.push_back(m);
            ans.push_back(out);
        }
    }

    rep(i,M.size()){
        cout << M[i] << " ";
        for(auto a:ans[i]) cout << a << " ";
        cout << endl;
    }
}