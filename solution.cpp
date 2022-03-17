#include <cstdio>

const int maxN (2000);
long long fact [maxN + 10];
long long f    [maxN + 10];
long long g    [maxN + 10];
long long h    [maxN + 10];
long long l    [maxN + 10];

const long long mod(1000000007);

long long qPow(long long base, long long expo)
{
	long long prod(1);
	for (long long i(1); i <= expo; i *= 2)
	{
		if (i & expo)
		{
			prod = prod * base % mod;
		}
		base = base * base % mod;
	}
	return prod;
}

long long inv(long long n)
{
	return qPow(n, mod - 2);
}

long long C(long long n, long long m)
{
	return fact[n] * inv(fact[m] * fact[n - m] % mod) % mod;
}

int main()
{
//	freopen("n^2.out", "w", stdout);

	fact[0] = 1;
	for (int n(1); n <= maxN; ++n)
	{
		fact[n] = fact[n - 1] * n % mod;
	}

	for (int n(0); n <= maxN; ++n)
	{
		l[n] = qPow(3, n);
	}

	h[0] = 1;
	for (int n(1); n <= maxN; ++n)
	{
		h[n] = (2 * (n * l[n - 1] + l[n]) - 1 + mod) % mod;
	}

	g[1] = 1;
	for (int n(2); n <= maxN; ++n)
	{
		for (int i(1); i <= n - 1; ++i)
		{
			g[n] = (g[n] + l[n - i - 1] * g[i]) % mod;
			f[n] = (f[n] + l[n - i - 1] * f[i] + h[n - i - 1] * g[i]) % mod;
			//printf("%d <- %d f:%lld g:%lld h:%lld l:%lld\n", n, i, f[i], g[i], h[n - i - 1], l[n - i - 1]);
		}
	}

	/*for (int n(2); n <= maxN; ++n)
	{
		printf("%d: %lld\n", n, f[n]);
	}//*/

	// freopen("strangelove.in", "r", stdin);
	// freopen("strangelove.out", "w", stdout);
	int n;
	scanf("%d", &n);
	printf("%lld\n", f[n]);

	return 0;
}
