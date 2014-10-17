import sys

n, k = map(int, sys.stdin.readline().split())

a = map(int, sys.stdin.readline().split())

def gcd(a, b):
    while a != 0:
        b %= a
        a ^= b
        b ^= a
        a ^= b
    return b

def lcm(a, b):
    return a * (b / gcd(a, b))

ans = 1000000000
MOD = 1000003
for i in xrange(n - k + 1):
    t = a[i]
    for j in xrange(1, k):
        t = lcm(t, a[i + j])
    ans = min(ans, t % MOD)

print ans

