#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    int s,t;
    cin >> s >> t;
    
    // a+b+c<=s
    // a*b*c<=t
    int ans=0;
    for(int a = 0; a <= s; a++){
        for(int b = 0; a+b <= s; b++){
            for(int c = 0; a+b+c <= s; c++){
                if(a*b*c <= t) {
                    ans++;
                    // printf("(a,b,c)=(%d,%d,%d)\n",a,b,c);
                }
            }
        }
    }   
    cout << ans << endl;
}