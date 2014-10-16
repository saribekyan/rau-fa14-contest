#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <cassert>
using namespace std;

#define MOD 1000003
#define M 100000

class MaxQueue {
private:
    stack< pair<int, int> > s1;
    stack< pair<int, int> > s2;

public:
    void push(int a) {
        if (s1.empty()) {
            s1.push(make_pair(a, a));
        } else {
            s1.push(make_pair(a, max(a, s1.top().second)));
        }
    }

    void pop() {
        if (s2.empty()) {
            int t = s1.top().first, m = t;
            s2.push(make_pair(t, m));
            s1.pop();
            while (!s1.empty()) {
                t = s1.top().first;
                s1.pop();
                m = max(m, t);
                s2.push(make_pair(t, m));
            }
        }
        s2.pop();
    }

    int get_max() {
        int m = 0;
        if (!s1.empty()) {
            m = max(m, s1.top().second);
        }
        if (!s2.empty()) {
            m = max(m, s2.top().second);
        }
        return m;
    }
};

vector<int> get_primes() {
    vector<bool> is_prime(M + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 4; i <= 500000; i += 2) {
        is_prime[i] = false;
    }
    
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i * i <= 500000; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 500000; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

vector<int> prime_cts(int &t, vector<int> &primes) {
    vector<int> cts(primes.size(), 0);
    for (int j = 0; j < primes.size(); ++j) {
        if (t % primes[j] == 0) {
            int c = 0;
            while (t % primes[j] == 0) {
                t /= primes[j];
                ++c;
            }
            cts[j] = c;
        }
    }
    return cts;
}

void solve(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    long long x1, y1;
    solve(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * x;
}

long long inverse(long long x) {
    long long inv, k;
    solve(MOD, x, k, inv);
    return (inv + MOD) % MOD;
}
int main() {
    // generate primes
    vector<int> primes = get_primes();
    int m = primes.size();

    // solve
    int n, k;
    scanf("%d%d", &n, &k);
    assert(1 <= n && n <= 10000);
    assert(1 <= k && k <= n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        assert(1 <= p[i] && p[i] <= M);
    }

    long long large_mul = 1;
    long long ans = MOD;

    vector<MaxQueue> prime_pows(m);
    vector<int> large_prime_count(M, 0);
    for (int i = 0; i < n; ++i) {
        int t = p[i];
        vector<int> c = prime_cts(t, primes);
        if (t != 1) {
            if (large_prime_count[t] == 0) {
                large_prime_count[t] = 1;
                large_mul = (large_mul * t) % MOD;
            } else {
                ++large_prime_count[t];
            }
        }
        for (int j = 0; j < m; ++j) {
            prime_pows[j].push(c[j]);
        }

        if (i >= k) {
            int t = p[i - k];
            prime_cts(t, primes);
            --large_prime_count[t];
            if (large_prime_count[t] == 0) {
                large_mul = (large_mul * inverse(t)) % MOD;
            }
            for (int j = 0; j < m; ++j) {
                prime_pows[j].pop();
            }
        }
        if (i >= k - 1) {
            long long tmp = large_mul;
            for (int j = 0; j < m; ++j) {
                int p = prime_pows[j].get_max();
                while (p--) {
                    tmp = (tmp * primes[j]) % MOD;
                }
            }
            ans = min(ans, tmp);
        }
    }

    printf("%lld\n", ans);

    return 0;
}

