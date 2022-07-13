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
    string S,T;
    cin >> S >> T;
    
    vector<pair<char,int>>  S1,T1;
    S1.push_back({S[0],1});
    int j = 0;
    for(int i = 1;i<S.size();++i){
        if(S1[j].first == S[i]){
            S1[j].second++;
        }else{
            j++;
            S1.push_back({S[i],1});
        }
    }

    j = 0;
    T1.push_back({T[0],1});
    for(int i=1; i<T.size();++i){
        if(T1[j].first == T[i]){
            T1[j].second++;
        }else{
            j++;
            T1.push_back({T[i],1});
        }
    }
    /*
    rep(i,S1.size()){
        cout << S1[i].first << "," << S1[i].second << endl;
    }
    rep(i,T1.size()){
        cout << T1[i].first << "," << T1[i].second << endl;
    }
    */
    // 比較
    bool ans = true;
    if (S1.size()!=T1.size()){
        ans = false;
        
    }else{
        rep(i,S1.size()){
            if(S1[i].first != T1[i].first){
                ans = false;
                break;
            }
            else if (S1[i].second > T1[i].second){
                ans = false;
                break;
            }
            else if (S1[i].second == 1 && S1[i].second != T1[i].second ){
                ans = false;
                break;
            }
        }
    }
    cout << (ans?"Yes":"No") << endl;
    
}
