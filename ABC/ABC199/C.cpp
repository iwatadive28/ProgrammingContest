#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    int N,Q;
    string S;
    cin >> N >> S >> Q;
    string S0,S1;
    S0 = S.substr(0,N);
    S1 = S.substr(N,2*N-1);
    
    // cout << S0 << S1 << endl;   

    rep(i,Q){
        int t,a,b;
        cin >> t >> a >> b;
        if (t==1){
            a--;b--;
            if(b<N){
                swap(S0[a],S0[b]);
            }
            else if(a>=N){
                swap(S1[a-N],S1[b-N]);
            }
            else{
                swap(S0[a],S1[b-N]);
            }

        }else if(t==2){
            swap(S0,S1);
        }
    }

    cout << S0 << S1 << endl;   
}
