#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main() {
	int N;
	cin >> N;

    bool mod3 = false;
    bool mod5 = false;
    
    rep(i,N){
        mod3 = ((i+1)%3 == 0);
        mod5 = ((i+1)%5 == 0);
        
        if (mod5&mod3){
            cout << "FizzBuzz" << endl;
        }else if(mod3){
            cout << "Fizz" << endl;
        }else if(mod5){
            cout << "Buzz" << endl;
        }else{
            cout << i+1 << endl;
        }        
    }

    return 0;
}