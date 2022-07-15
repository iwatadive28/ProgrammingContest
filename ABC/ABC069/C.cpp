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
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    
    // 因数2が(0，1，2以上)の数
    int c0=0,c1=0,c2=0;
    rep(i,N){
        if (a[i]==0) c0++;
        else if(a[i]%4==0) c2++;
        else if(a[i]%2==0) c1++;
        else c0++;
    }

    bool ans = true;
    if     (c1<=1 && (c0+c1-1)>c2) ans = false;
    else if(c1>=2 && c0>c2)        ans = false;    

    cout << (ans?"Yes":"No") << endl;
}
