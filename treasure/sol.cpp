#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    while (true) {
        double s = x * (((double) rand()) / RAND_MAX);
        double t = y * (((double) rand()) / RAND_MAX);
        printf("%.5lf %.5lf\n", s, t);

        char res[10];
        scanf("%s", res);
        if (res[0] == 'Y') {
            break;
        }
    }
    return 0;
}

