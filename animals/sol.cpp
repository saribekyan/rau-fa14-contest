#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

#define P 999983

bool exists(vector<string> &d, int l) {
    if (l == 0) {
        return true;
    }
    int n = d.size();

    long long pw = 1;
    for (int i = 0; i < l; ++i) {
        pw = pw * P;
    }

    vector<long long> hashes;
    for (int i = 0; i < n; ++i) {
        int m = d[i].size();
        if (l > m) {
            return false;
        }
        vector<long long> h(m - l + 1, 0);
        for (int j = 0; j < m; ++j) {
            if (j < l) {
                h[0] = h[0] * P + d[i][j];
            } else {
                h[j - l + 1] = (h[j - l] * P + d[i][j]) - d[i][j - l] * pw;
            }
        }

        sort(h.begin(), h.end());
        if (i == 0) {
            hashes = h;
        } else {
            int k = 0;
            for (int j = 0; j < hashes.size(); ++j) {
                if (binary_search(h.begin(), h.end(), hashes[j])) {
                    hashes[k++] = hashes[j];
                }
            }

            if (k == 0) {
                return false;
            }
            hashes.resize(k);

        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    assert(1 <= n && n <= 100);
    vector<string> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        assert(1 <= d[i].size() && d[i].size() <= 1000);
        for (int j = 0; j < d[i].size(); ++j) {
            assert('a' <= d[i][j] && d[i][j] <= 'z');
        }
    }
   
    int p = 0, q = d[0].length();
    while (q - p > 1) {
        int m = (p + q) / 2;
        if (exists(d, m)) {
            p = m;
        } else {
            q = m;
        }
    }

    while (q >= p) {
        if (exists(d, q)) {
            printf("%d\n", q);
            return 0;
        }
        --q;
    }
    assert(false);
    return 0;
}

