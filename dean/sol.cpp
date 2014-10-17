#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> par, rnk;

pair<int, int> find(int p) {
    if (par[p] == -1) {
        return make_pair(p, 0);
    }
    if (par[par[p]] == -1) {
        return make_pair(p, 1);
    }
    if (par[par[par[p]]] == -1) {
        return make_pair(p, 2);
    }
    pair<int, int> pr = find(par[par[p]]);
    par[p] = par[pr.first];
    return pr;
}

int par_dist(pair<int, int> u) {
    int p = u.first;
    while (u.second--) {
        p = par[p];
    }
    return p;
}

void join(int p, int q) {
    pair<int, int> u = find(p);
    pair<int, int> v = find(q);
    if (par_dist(u) == par_dist(v)) {
        return;
    }

    p = u.first;
    q = v.first;
    if (rnk[p] < rnk[q]) {
        swap(p, q);
        rnk[p] += rnk[q];
    }

    if (par[q] != -1) {
        if (par[par[q]] != -1) {
            par[par[par[q]]] = p;
        }
        par[par[q]] = q;
    }
    par[q] = p;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    par.assign(n, -1);
    rnk.assign(n, 1);
    int t = 1;
    while (m--) {
        char op[2];
        int p, q;
        scanf("%s%d%d", op, &p, &q);
        --p; --q;
        if (op[0] == 'D') {
            pair<int, int> u = find(p);
            pair<int, int> v = find(q);
            int x = 0;
            if (par_dist(u) != par_dist(v)) {
                x = 0;
            } else if ((u.second + v.second) % 2 == 0) {
                x = 1;
            } else {
                x = 2;
            }
            if (x == 1) {
                assert(false);
                return 0;
            }
            join(p, q);
        } else {
            pair<int, int> u = find(p);
            pair<int, int> v = find(q);
            if (par_dist(u) != par_dist(v)) {
                printf("Unknown\n");
            } else if ((u.second + v.second) % 2 == 0) {
                printf("Same\n");
            } else {
                printf("Different\n");
            }
        }
        t++;
    }
    return 0;
}

