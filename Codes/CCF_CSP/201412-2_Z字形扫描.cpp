#include<cstdio>
const int maxn=510;
int n, G[maxn][maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
	  		scanf("%d", &G[i][j]);
	printf("%d ", G[1][1]);
	if(n == 1) return 0;
	int tot = 1, d = -1, x = 1, y = 2;	// d = 1: up, d = -1: down
	while(tot <= n * n - 1)
	{
		tot++;
		printf("%d ", G[x][y]);
		if(y == n && d == 1)
		{
			x++;
			d = -1;
		}
		else if(x == 1 && d == 1)
		{
			y++;
			d = -1;
		}
		else if(x == n && d == -1)
		{
			y++;
			d = 1;
		}
		else if(y == 1 && d == -1)
		{
			x++;
			d = 1;
		}
		else if(d == -1)
		{
			x++;
			y--;
		}
		else if(d == 1)
		{
			x--;
			y++;
		}
	}
	return 0;
}
