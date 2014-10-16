#include <stdio.h>

int main() {
    double X, Y;
    scanf("%lf%lf", &X, &Y);
    fprintf(stderr, "got %lf %lf\n", X, Y);
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            printf("%d %d\n", i, j);
            fprintf(stderr, "try: %d %d\n", i, j);
            fflush(stdout);
            char s[10]; 
            scanf("%s", s);
            fprintf(stderr, "got: %s\n", s);
            if (s[0] == 'Y') {
                return 0;
            }
        }
    }
    return 0;
}

