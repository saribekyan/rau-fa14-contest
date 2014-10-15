#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    double x, y;
    scanf("%lf %lf", &x, &y);
    cerr << "got " << x << ' ' << y << '\n';

    int step = 1;
    while (true) {
        double s = x * (((double) rand()) / RAND_MAX);
        double t = y * (((double) rand()) / RAND_MAX);
        //cerr << s << ' ' << t << '\n' << flush;
        printf("%.10lf %.10lf\n", s, t);
        fflush(stdout);

        char res[10];
        scanf("%s", res);
        if (res[0] == 'Y') {
            cerr << "steps: " << step << '\n';
            break;
        }
        ++step;
    }
    return 0;
}

