#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

typedef double myDouble;

struct pt {
	myDouble x, y;
 
	pt operator- (pt p) {
		pt res = { x-p.x, y-p.y };
		return res;
	}
};
 
struct circle : pt {
	myDouble r;
};
 
struct line {
	myDouble a, b, c;
};
 
const myDouble EPS = 1E-9;
 
myDouble sqr (myDouble a) {
	return a * a;
}

void tangents (pt c, myDouble r1, myDouble r2, vector<line> & ans) {
	myDouble r = r2 - r1;
	myDouble z = sqr(c.x) + sqr(c.y);
	myDouble d = z - sqr(r);
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

bool intersect(line L, const circle& c)
{
    myDouble D =sqrt( L.a*L.a + L.b*L.b);
    L.a /= D;
    L.b /= D;
    L.c /= D;
    if (fabs(L.a * c.x + L.b * c.y + L.c) <= c.r)
        return true;
    return false;
}

bool intersect(myDouble x1, myDouble x2, myDouble x3, myDouble x4)
{
    if (x1 <= x3 && x3 <= x2)
        return true;
    if (x1 <= x4 && x4 <= x2)
        return true;
    if (x3 <= x1 && x1 <= x4)
        return true;
    if (x3 <= x2 && x2 <= x4)
        return true;
    return false;
}

int dir(const circle& c, line L)
{
    myDouble D =sqrt( L.a*L.a + L.b*L.b);
    L.a /= D;
    L.b /= D;
    L.c /= D;
    if (L.a * c.x + L.b * c.y + L.c >= 0)
        return 1;
    return 0;
}

int n, X, Y;

circle c[370];
myDouble speed[370];

const myDouble eps = 0.00001;
const myDouble MAXIM = 1000000000.0;

myDouble gr[370][370];
myDouble d[370][370];

int main()
{
    cin >> n >> X >> Y;

    for (int i = 0; i < 370; ++i)
        for (int j = 0; j < 370; ++j)
            gr[i][j] = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> c[i].x >> c[i].y >>c[i].r;
        speed[i] = 4.0 * acos(0.0) * c[i].r;
    }

    c[n].x = 0; c[n].y = 0; c[n].r = eps; speed[n] = MAXIM;
    c[n + 1].x = X; c[n + 1].y = Y; c[n + 1].r = eps; speed[n + 1] = MAXIM;
    n += 2;

    for (int i = 0; i < n; ++i)
        for (int i1 = 0; i1 < 2; i1++)
        for (int j = 0; j < n; ++j)
        for (int j1 = 0; j1 < 2; j1++)
            if (i != j)
        {
            bool e = false;
            vector <line> L = tangents(c[i], c[j]);
            for (int k = 0; k <  L.size() && !e; ++k)
                if (dir(c[i], L[k]) == i1 && dir(c[j], L[k]) == j1)
            {
                bool f = true;
                for (int g = 0; g < n && f; ++g)
                    if (g != i && g != j && (intersect(L[k], c[g]) && intersect(c[g].x - c[g].r, c[g].x + c[g].r, 
                        c[i].x, c[j].x) && intersect(c[g].y - c[g].r, c[g].y + c[g].r, c[i].y, c[j].y)))
                        f = false;
                if (f)
                    e = true;
            }
            if (e)
            {
                gr[i + n * i1][j + n * j1] = min(speed[i], speed[j]);                
            }
            else
            {
                gr[i + n * i1][j + n * j1] = 0;
            }
        }

    int N = n;

    n *= 2;

    /*ofstream out("output.txt");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            out << fixed << setprecision(6) << gr[i][j] << " ";
        out << endl;
    }*/

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = gr[i][j];
    
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][j]  < min(d[i][k], d[k][j]))
                    d[i][j] = min(d[i][k], d[k][j]);

    /*out << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            out << fixed << setprecision(6) << d[i][j] << " ";
            if (fabs(d[i][j] - 41478705) < 1)
                cout << i << " " << j << endl;
        }
        out << endl;
    }*/

    myDouble answer = max(max(d[N - 2][N - 1], d[N - 2][N - 1 + N]),
                        max(d[N + N - 2][N - 1], d[N + N - 2][N - 1 + N]));

    if (answer > MAXIM - 100)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(6) << answer << endl;

}
