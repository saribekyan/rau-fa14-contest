#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int l, r;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;
 
bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int m;
    scanf("%d%d%d", &l, &r, &m);
    assert(1 <= l && l <= 100);
    assert(1 <= r && r <= 100);
    assert(0 <= m && m <= 10000);
    g.resize(l);
    vector<int> cl(l), cr(r);
    for (int i = 0; i < l; ++i) {
        cl[i] = i;
    }
    for (int i = 0; i < r; ++i) {
        cr[i] = l + i;
    }

    while (m--) {
        int p, q;
        scanf("%d%d", &p, &q);
        assert(1 <= p && p <= l);
        assert(1 <= q && q <= r);
        --p; --q;
        g[p].push_back(q);
        if (cl[p] == cr[q]) {
            continue;
        }
        int c1 = cl[p];
        int c2 = cr[q];
        for (int i = 0; i < l; ++i) {
            if (cl[i] == c1) {
                cl[i] = min(c1, c2);
            }
        }
        for (int i = 0; i < r; ++i) {
            if (cr[i] == c2) {
                cr[i] = min(c1, c2);
            }
        }
    }

    mt.assign(r, -1);
    for (int v = 0; v < l; ++v) {
        used.assign(l, false);
        try_kuhn(v);
    }

    int comp = 0;
    for (int i = 0; i < l + r; ++i) {
        int cnt = 0;
        for (int j = 0; j < l; ++j) {
            if (cl[j] == i) {
                ++cnt;
            }
        }
        comp += (cnt != 0);
        int in_matching = 0;
        for (int j = 0; j < r; ++j) {
            if (cr[j] == i && mt[j] != -1) {
                ++in_matching;
            }
        }
        if (cnt != in_matching) {
            printf("Samvel\n");
            return 0;
        }
    }
    printf("Mihran\n");
    return 0;
}

