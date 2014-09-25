#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int m = 0, c = 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[i + 1]) {
            if (m < c) {
                ans += (c - m) * a[i] * a[i] * a[i];
                m = c;
            }
            c = 1;
        } else {
            c += 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

