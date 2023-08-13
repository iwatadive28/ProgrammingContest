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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    vector<int>  t(Q,0),x(Q,0);
    vector<char> a(Q,'a');
    rep(i,Q) cin >> t[i] >> x[i] >> a[i];
            
    for(int i=Q-1;i>=0;--i){
        if(t[i]==1) continue;

        for(int j=0;j<=i;j++){
            if(t[i]==2){
                a[j] = tolower(a[j]);
            }
            else if(t[i]==3){
                a[j] = toupper(a[j]);
            }
        }

        for(int j=0;j<N;j++){
            if(t[i]==2){
                S[j] = tolower(S[j]);
            }
            else if(t[i]==3){
                S[j] = toupper(S[j]);
            }
        }
        
        break;        
    }

    rep(i,Q){
        if(t[i]==1 && x[i]!=0){
            S[x[i]-1] = a[i];
        }
    }
    cout << S << endl;
}