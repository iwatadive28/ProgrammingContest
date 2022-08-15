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
int ctoi(char c){
    int res = c - '0';
    return res;
}

vector<ll> itovec(auto x){
    vector<ll> res;
    while(x>0){
        res.push_back(x%10);
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

void printVec(auto vec){
    for(auto x:vec){
        cout << x << " ";
    }
    cout << endl;
    return;
}

int main(){
    string S;
    cin >> S;
    vector<ll> cnt(10,0);
    for(char c:S){
        cnt[ctoi(c)]++;
    }
    // printVec(cnt);
    
    bool ans = false;
    if(S.size()==1) ans = (S=="8");
    else if(S.size() == 2){
        if(stoi(S)%8 == 0) ans = true;
        swap(S[0],S[1]);
        if(stoi(S)%8 == 0) ans = true;
    }
    else{ // 下3桁 112~992を作ることができるか判定する
        for(int i=104;i<1000;i+=8){
            vector<ll> iv  = itovec(i);
            vector<ll> cnt_tmp = cnt;
            bool ans_tmp = true;
            for(ll n:iv){
                cnt_tmp[n]--;
                if(cnt_tmp[n]<0) {
                    ans_tmp = false;
                }
            }
            if(ans_tmp){
                ans = true;
            }
        }
    }

    cout << (ans?"Yes":"No") << endl;
}
