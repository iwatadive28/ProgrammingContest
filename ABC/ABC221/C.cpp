#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    string N;
    cin >> N;
    sort(N.begin(),N.end());
    reverse(N.begin(),N.end());
    // rep(i,N.length()) cout << N[i] << endl;

    ll n1=0,n2=0;
    n1 = ctoi(N[0]);
    for (int i=1;i<N.length();++i){
        if (n1>n2){
            n2 = n2*10+ctoi(N[i]);
        }
        else{
            n1 = n1*10+ctoi(N[i]);
        }
        // cout <<"n1,n2=" << n1 << ","<< n2 << endl;
    }
    cout << n1*n2 << endl;
}