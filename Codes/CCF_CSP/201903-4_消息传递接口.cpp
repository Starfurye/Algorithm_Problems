#include <bits/stdc++.h>
const int maxn = 10000;
using namespace std;
struct tInst {
    int op;
    int pid;
};
tInst inst[maxn+10][10];
int instNum[maxn+10];

int instCmp[maxn+10];
int instBlk[maxn+10];
int numCmp, numBlk;

int main ()
{
    int T, n;
    scanf("%d%d", &T, &n);
    getchar();

    while (T--)
    {
        memset(instNum, 0, sizeof(instNum));
        for (int i = 0; i <= n - 1; i++)
        {
            char str[100];
            scanf("%[^\n]", str + 1);
            getchar();
            for (int j = 1, op = 0, pid = 0; ; j++)
            {
                if (str[j] == 'R')
                    op = 0;
                else if (str[j] == 'S')
                    op = 1;
                else if (str[j] >= '0' && str[j] <= '9')
                    pid = pid * 10 + str[j] - '0';
                else if (str[j] == ' ')
                {
                    inst[i][++instNum[i]].op = op;
                    inst[i][instNum[i]].pid = pid;
                    pid = 0;
                }
                else
                {
                    inst[i][++instNum[i]].op = op;
                    inst[i][instNum[i]].pid = pid;
                    break;
                }
            }
        }

        memset(instCmp, 0, sizeof(instCmp));
        memset(instBlk, 0, sizeof(instBlk));
        numCmp = numBlk = 0;

        int x = 0;
        while (numCmp + numBlk != n)
        {
            while (instCmp[x] != instNum[x] && !instBlk[x])
            {
                int y = instCmp[x] + 1;
                int op = inst[x][y].op, pid = inst[x][y].pid;
                int xx = pid;
                if (instCmp[xx] != instNum[xx])
                {
                    int yy = instCmp[xx] + 1;
                    if (op + inst[xx][yy].op == 1 && x == inst[xx][yy].pid)
                    {
                        instCmp[x] ++; instCmp[xx] ++;
                        if (instCmp[x] == instNum[x])
                            numCmp ++;
                        if (instCmp[xx] == instNum[xx])
                            numCmp ++;
                        if (instBlk[xx])
                        {
                            instBlk[xx] = 0;
                            numBlk --;
                        }
                    }
                    else
                    {
                        instBlk[x] = 1;
                        numBlk ++;
                    }
                }
                else
                {
                    instBlk[x] = 1;
                    numBlk ++;
                }
            }
            x = (x + 1) % n;
        }

        if (numCmp == n)
            printf("0\n");
        else
            printf("1\n");

    }

    return 0;
}
