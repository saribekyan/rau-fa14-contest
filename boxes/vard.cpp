#include <cstdio>
#include <cassert>
using namespace std;

int n;
int a[10010] = {0};

int main()
{
	int i, k;
	long long j, s = 0;
	scanf("%d", &n);
	assert(n > 0 && n <= 100000);
	while (n--)
	{
		scanf("%d", &i);
		assert(i > 0 && i <= 10000);
		++a[i];
	}
        k = 0;
	for (j = 10000; j > 0; --j)
	{
		if (a[j] > k)
		{
			s += j * j * j * (a[j] - k);
			k = a[j];
		}	
	}
	
	printf("%lld\n", s);
	return 0;
}
