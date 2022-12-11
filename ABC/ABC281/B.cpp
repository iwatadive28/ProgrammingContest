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
    string S;
    cin >> S;    
    ll n = S.size();

    // 大文字か？
    if (!('A'<=S[0] && S[0]<='Z')){
        cout << "No" << endl;
        return 0;
    } 
    if (!('A'<=S[n-1] && S[n-1]<='Z')){
        cout << "No" << endl;
        return 0;
    }

    // 数字か？
    int cnt = 0;
    string s;
    for(ll i=1;i<n-1;i++){
        if (!('0'<=S[i] && S[i]<='9')){
            cout << "No" << endl;
            return 0;
        }
        s+=S[i];
        cnt++;
    }

    if(cnt!=6){
        cout << "No" << endl;
        return 0;
    }

    ll x = stoll(s);
    // cout << s << ","<< x <<endl;

    if(x>=100000 && x<=999999){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}