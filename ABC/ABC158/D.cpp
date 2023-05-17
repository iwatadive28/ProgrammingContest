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
    string S;
    int Q;
    cin >> S >> Q;
    
    string fr,bk;
    int iv = 1;
    rep(q,Q){
        int t;
        cin >> t;
        if(t==1){
            iv *= -1;
        }else if(t==2){
            int f;
            char c;
            cin >> f >> c;
            if((f==1&&iv==1)||(f==2&&iv==-1)){
                fr+=c;
            }else{
                bk+=c;
            }
        }
    }
    reverse(fr.begin(),fr.end());
    string ans = fr + S + bk;
    if(iv==-1) reverse(ans.begin(),ans.end());
    
    cout << ans << endl;
    
}