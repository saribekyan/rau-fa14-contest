#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

long long min(long long a, long long b) {
    if (a < b) {
        return a;
    }
    return b;
}
int main() {
    long long n;
    scanf("%lld", &n);
    assert(1 <= n && n <= 200);
    vector<long long> a(2 * n + 1, 0), s(2 * n + 1, 0);
    for (long long i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        assert(1 <= a[i] && a[i] <= 500);
        a[i + n] = a[i];
    }
    for (long long i = 1; i < 2 * n + 1; ++i) {
        s[i] = s[i - 1] + a[i];
    }

    vector< vector<int> > d(2 * n + 1, vector<int> (2 * n + 1, 0));
    for (long long l = 2; l <= n; ++l) {
        for (long long i = 1; i + l - 1 <= 2 *n; ++i) {
            long long j = i + l - 1;
            d[i][j] = 1000000000;
            for (long long k = i; k < j; ++k) {
                d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + max(s[k] - s[i - 1], s[j] - s[k]));
            }
        }
    }

    long long ans = 1000000000;
    for (long long i = 1; i <= n; ++i) {
        ans = min(ans, d[i][i + n - 1]);
    }
    printf("%lld\n", ans);
    return 0;
}

