#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int p;
    scanf("%d", &p);
    while (p--) {
        int goal = 0;
        for (int i = 0; i < 3; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < 3; ++j) {
                goal <<= 1;
                if (s[j] == '*') {
                    goal |= 1;
                }
            }
        }

        int ans = 10;
        int di[5] = {-3, -1, 0, 1, 3};
        for (int mask = 0; mask < (1 << 9); ++mask) {
            int tmp = 0, cnt = 0;
            for (int i = 0; i < 9; ++i) {
                if (mask & (1 << i)) {
                    ++cnt;
                    for (int j = 0; j < 5; ++j) {
                        if (0 <= i + di[j] && i + di[j] < 9 &&
                            ((i + di[j]) / 3 == i / 3 || (i + di[j]) % 3 == i % 3)) {
                            tmp ^= (1 << (i + di[j]));
                        }
                    }
                }
            }
            if (tmp == goal) {
                ans = min(ans, cnt);
            }
        }
        if (ans == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}

