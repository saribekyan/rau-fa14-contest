#include <iostream>
#include <vector>
#include <cmath>
#include "testlib.h"
using namespace std;

#define M 30000

#define OK 0
#define PE 2

int main(int argc, char * argv[]) {
    setName("interacts with user program");
    registerInteraction(argc, argv);

    int X = inf.readInt(0, 100);
    int Y = inf.readInt(0, 100);
    int n = inf.readInt(3, 100);
    cout << X << ' ' << Y << '\n' << flush;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        x[i] = inf.readDouble(0, X);
        y[i] = inf.readDouble(0, Y);
    }
    inf.close();

    x.push_back(x[0]);
    y.push_back(y[0]);

    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        area += x[i] * y[i + 1] - x[i + 1] * y[i];
    }
    area = fabs(area);

    for (int m = 0; m < M; ++m) {
        double p = ouf.readDouble(0, X);
        double q = ouf.readDouble(0, Y);

        double tmp = 0.0;
        for (int i = 0; i < n; ++i) {
            tmp += fabs(p * y[i] + x[i] * y[i + 1] + x[i + 1] * q -
                       (x[i] * q + y[i] * x[i + 1] + y[i + 1] * p));
        }
        if (fabs(tmp - area) < (1e-5)) {
            cout << "Yes\n" << flush;
            tout << 0 << flush;
            return OK;
        } else {
            cout << "No\n" << flush;
        }
    }
    tout << PE << flush;
    return PE;
}

