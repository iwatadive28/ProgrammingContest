#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)  for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    ll N;
    cin >> N;

    ll ans=0;
    
    for(long long a=1;a*a*a<=N;a++){
		for(long long b=a;a*b*b<=N;b++){
			ans+=N/a/b-b+1;
		}
	}  
    
    cout << ans << endl;
}