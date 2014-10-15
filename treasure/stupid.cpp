#include <stdio.h>

int main() {
    double X, Y;
    scanf("%lf%lf", &X, &Y);
    for (int i = 0; i < 100000; ++i) {
        printf("1.0 1\n");
        fflush(stdout);
        char s[10];
        scanf("%s", s);
        if (s[0] == 'Y') {
            break;
        }
    }
    return 0;
}

