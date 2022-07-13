N = int(input())
ans = 0

n = N
keta = 0
while(n>=1):
    n = n/10
    keta = keta+1

for i in range(keta):
    ne = (pow(10,i+1) - pow(10,i))
    if (i==keta-1):
        ne = N - pow(10,i)+1
    sum = ((1+ne)*ne)/2
    ans = (ans + sum)% 998244353

print(int(ans % 998244353))