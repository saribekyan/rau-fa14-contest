#include <cstdio>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

#define N 300
#define MAX 100000000

struct pt {
        double x, y;
         
            pt operator- (pt p) {
                        pt res = { x-p.x, y-p.y };
                                return res;
                                    }
};
 
struct circle : pt {
        double r;
};
 
struct line {
        double a, b, c;
};
 
const double EPS = 1E-9;
 
double sqr (double a) {
        return a * a;
}

void tangents (pt c, double r1, double r2, vector<line> & ans) {
        double r = r2 - r1;
            double z = sqr(c.x) + sqr(c.y);
                double d = z - sqr(r);
                    if (d < -EPS)  return;
                        d = sqrt (abs (d));
                            line l;
                                l.a = (c.x * r + c.y * d) / z;
                                    l.b = (c.y * r - c.x * d) / z;
                                        l.c = r1;
                                            ans.push_back (l);
}
 
vector<line> tangents (circle a, circle b) {
        vector<line> ans;
            for (int i=-1; i<=1; i+=2)
                        for (int j=-1; j<=1; j+=2)
                                        tangents (b-a, a.r*i, b.r*j, ans);
                for (size_t i=0; i<ans.size(); ++i)
                            ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
                    return ans;
}

int main() {
    int n;
    long long X, Y;
    scanf("%d%lld%lld", &n, &X, &Y);
    assert(0 <= n && n <= N);
    assert(-MAX <= X && X <= MAX);
    assert(-MAX <= Y && Y <= MAX);
    vector<long long> x(n), y(n), r(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &x[i], &y[i], &r[i]);
        assert(-MAX <= x[i] && x[i] <= MAX);
        assert(-MAX <= y[i] && y[i] <= MAX);
        assert(-MAX <= r[i] && r[i] <= MAX);
    }

    x.push_back(0);
    y.push_back(0);
    r.push_back(0);
    x.push_back(X);
    y.push_back(Y);
    r.push_back(0);
    n += 2;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            assert((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > (r[i] + r[j]) * (r[i] + r[j]));
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            circle a;
            a.x = x[i];
            a.y = y[i];
            a.r = r[i];
            circle b;
            b.x = x[j];
            b.y = y[j];
            b.r = r[j];

            vector<line> v = tangents(a, b);

            for (int k = j + 1; k < n; ++k) {
                for (int ln = 0; ln < v.size(); ++ln) {
                    line l = v[ln];
                    //printf("%lf %lf %lf\n", l.a, l.b, l.c);
                    double dist = fabs(l.a * x[k] + l.b * y[k] + l.c) / sqrt(l.a * l.a + l.b * l.b);
                    //printf("%lf %lld\n", dist, r[k]);
                   
                    if (fabs(dist - r[k]) < EPS) {
                        printf("%d %d %d\n", i, j, k);
                        printf("%lld %lld %lld\n", x[i], y[i], r[i]);
                        printf("%lld %lld %lld\n", x[j], y[j], r[j]);
                        printf("%lld %lld %lld\n", x[k], y[k], r[k]);
                        printf("%lf %lf %lf\n", l.a, l.b, l.c);
                        assert(false);
                    }
                }
            }
        }
    }
    return 0;
}

