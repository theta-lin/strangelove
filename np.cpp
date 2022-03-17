#include <cstdio>
#include <vector>

const int maxN (16);
bool      visit[maxN + 10][maxN + 10];

const long long mod(1000000007);

int n;
long long ans;

std::vector<int> forward;
std::vector<int> back;

void print(int sum)
{
	printf("---\n");
	printf("sum: %d\n", sum);
	{
		int j(1);
		for (size_t i(0); i < forward.size(); ++i)
		{
			while (j < forward[i])
			{
				printf(">");
				++j;
			}
			printf("%d", j);
			++j;
		}
	}
	printf("\n");
	{
		int j(1);
		for (size_t i(back.size() - 1); ~i; --i)
		{
			while (j < back[i])
			{
				printf("<");
				++j;
			}
			printf("%d", j);
			++j;
		}
	}
	printf("\n");
	printf("---\n");
}

void dfs2(int pos, int sum)
{
	back.push_back(pos);
	if (pos == 1)
	{
		ans = (ans + sum) % mod;
		print(sum);
	}
	else
	{
		for (int i(pos - 1); i >= 1; --i)
		{
			dfs2(i, sum + !visit[i][pos]);
		}
	}
	back.pop_back();
}

void dfs1(int pos, int sum)
{
	forward.push_back(pos);
	if (pos == n)
	{
		dfs2(n, sum);
	}
	else
	{
		for (int i(pos + 1); i <= n; ++i)
		{
			visit[pos][i] = true;
			dfs1(i, sum + 1);
			visit[pos][i] = false;
		}
	}
	forward.pop_back();
}

int main()
{
//	freopen("strangelove.in", "r", stdin);
//	freopen("strangelove.out", "w", stdout);
	scanf("%d", &n);
	dfs1(1, 0);
	printf("%lld\n", ans);
	
	/*for (int i(2); i <= maxN; ++i)
	{
		n = i;
		ans = 0;
		dfs1(1, 0);
		printf("%d: %lld\n", i, ans);
	}//*/
	
	return 0;
}
