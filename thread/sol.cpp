#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const double PI  = 2 * acos(0.0);
const double EPS = (1e-9);

struct Line {
    double a, b, c;
    long long a2b2;

    double dist(long long x, long long y) {
        return fabs(a * x + b * y + c) / sqrt(a2b2);
    }
};

Line get_line(long long R, long long x, long long y, long long r, int type) {
    Line l;
    long long rR;
    if (type == 0) {
        rR = R - r;
    } else {
        rR = R + r;
    }
    l.a2b2 = x * x + y * y;
    l.a = ( x * rR + y * sqrt(x * x + y * y - rR * rR)) / sqrt(x * x + y * y);
    l.b = (-x * sqrt(x * x + y * y - rR * rR) + y * rR) / sqrt(x * x + y * y);
    l.c = -R * sqrt(x * x + y * y);
    return l;
}

int dir(double a, double b, double c, double d) {
    double p = a * d - b * c;
    if (p > EPS) {
        return 1;
    }
    if (p < -EPS) {
        return -1;
    }
    return 0;
}

int main() {
    int n, X, Y;
    scanf("%d%d%d", &n, &X, &Y);
    vector<int> x(n + 2), y(n + 2), r(n + 2);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &r[i]);
    }
    x[n] = 0;
    y[n] = 0;
    r[n++] = 0;

    x[n] = X;
    y[n] = Y;
    r[n++] = 0;

    vector< vector<int> > g(2 * n, vector<int>(2 * n, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
              
                for (int type = 0; type < 2; ++type) {
                    Line l = get_line(r[i], x[j] - x[i], y[j] - y[i], r[j], type);
                    int k;
                    for (k = 0; k < n; ++k) {
                        if (k != i && k != j) {
                            if (i == 7 && j == 11 && (k == 1 || k == 3)) {
                                i = i;
                            }
                            if (l.dist(x[k] - x[i], y[k] - y[i]) < r[k] &&
                                dir(x[k] - x[i], y[k] - y[i], l.a, l.b) * dir(x[k] - x[j], y[k] - y[j], l.a, l.b) <= 0) {
                                break;
                            }
                        }
                    }
                    if (k == n) {
                        if (i + j == 2 * n - 3) {
                            printf("-1\n");
                            return 0;
                        }
                        if (i >= n - 2 || j >= n - 2) {
                            g[2 * i][2 * j + type] = g[2 * j + 1 - type][2 * i + 1] = r[min(i, j)];
                        } else {
                            g[2 * i][2 * j + type] = g[2 * j + 1 - type][2 * i + 1] = min(r[i], r[j]);
                        }
                    }
                }
            }
        }
    }

    vector< vector<int> > cnt( 2 * n, vector<int>(2 * n, 0));
    vector< vector<int> > pred( 2 * n, vector<int>(2 * n, 0));
    for (int i = 0; i < 2 * n; ++i)
        for (int j = 0; j < 2 * n; ++j) {
            cnt[i][j] = (g[i][j] != -1);
            pred[i][j] = i;
        }

    /* printf("%4d", -1);
    for (int i = 0; i < 2 * n; ++i) {
        printf("%4d", i);
    }
    putchar('\n');
    for (int i = 0; i < 2 * n; ++i) {
        printf("%3d:", i);
        for (int j = 0; j < 2 * n; ++j) {
            printf("%4d", g[i][j]);
        }
        putchar('\n');
    } */


    for (int k = 0; k < 2 * n; ++k) {
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                if (g[i][k] != -1 && g[k][j] != -1 &&
                    (g[i][j] == -1 || g[i][j] < min(g[i][k], g[k][j]))) {
                    g[i][j] = min(g[i][k], g[k][j]);
                    cnt[i][j] = cnt[i][k] + cnt[j][k];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }

    int R = 0, p, q;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (R < g[2 * (n - 2) + i][2 * (n - 1) + j]) {
                p = 2 * (n - 2) + i;
                q = 2 * (n - 1) + j;
            }
            R = max(R, g[2 * (n - 2) + i][2 * (n - 1) + j]);
        }
    }
    printf("%.5lf\n", 2 * PI * R);
   /* printf("%d %d %.5lf\n", R, cnt[p][q], 2 * PI * R);

     while (q != p) {
        printf(" %d\n", q);
        q = pred[p][q];
    }*/
    return 0;
}

