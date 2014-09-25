#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char s[100010];
int main() {
    scanf("%s", s);
    int n = strlen(s);

    int p = 0, q = 0;
    for (int i = 0; i < n; ++i) {
        q += s[i] - '0';
    }
    q = n - q;
    vector< vector< int > > d(1, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            d[0][p++] = i;
        } else {
            d[0][q++] = i;
        }
    }

    for (int t = 1; (1<<t) <= n; ++t) {
        d.push_back(vector<int>(n));
        for (int i = 0; i < n; ++i) {
            d[t][i] = d[t - 1][d[t - 1][i]];
        }
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int i, j;
        scanf("%d%d", &i, &j);
        j += 1;
        int p = i;
        for (int k = 0; (1<<k) <= j; ++k) {
            if (j & (1<<k)) {
                p = d[k][p];
            }
        }
        printf("%c\n", s[p]);
    }
    return 0;
}

