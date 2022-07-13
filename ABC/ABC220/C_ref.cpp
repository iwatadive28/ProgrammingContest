#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

ll ara[100001];
int main()
{
    ll i;
    ll n,x,sum=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin>>ara[i];
        sum+=ara[i];
    }

    cin >> x;
    ll b=x/sum;
    x-=b*sum;
    
    for(i=1;i<=n;i++){
        if(x<ara[i])
            break;
        x-=ara[i];
    }
    cout<<b*n+i<<endl;
}