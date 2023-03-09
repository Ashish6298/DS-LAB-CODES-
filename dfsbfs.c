#include <stdio.h>
#include <stdlib.h>
int st[10], top = -1, v[10], a[10][10], u[10];
int n, q[10], front = 0;
int rear = -1;

void dfs(int s)
{
    int i;
    st[++top] = s;
    v[s] = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[s][i] == 1 && v[i] == 0)
        {
            printf("%d->%d\n", s, i);
            dfs(i);
        }
    }
}

void bfs(int s)
{
    int i, m;
    u[s] = 1;
    q[++rear] = s;
    printf("Nodes reacghable %d\n", s);
    while (front <= rear)
    {
        m = q[front++];
        for (i = 1; i <= n; i++)
        {
            if (a[m][i] == 1 && u[i] == 0)
            {
                q[++rear] = i;
                printf("%d\n", i);
                u[i] = 1;
            }
        }
    }
}

void main()
{
    int i, s, j, ch;
    while (1)
    {
        printf("1.create\n2.DFS\n3.BFS\n4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the nomber of officers\n");
            scanf("%d", &n);
            printf("Enter the adjancey matrix\n");
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    scanf("%d", &a[i][j]);
                }
            }
            break;

        case 2:
            printf("Reachable nodes usong DFS\n");
            printf("Enter your source\n");
            scanf("%d", &s);
            printf("Nodes reachable is %d\n", s);
            dfs(s);
            for (i = 1; i <= n; i++)
            {
                if (v[i] == 0)
                {
                    printf("%d is not visite\n", i);
                }
            }

            break;

        case 3:
            printf("Reachable node usnig BFS\n");
            printf("Enter your source1\n");
            scanf("%d", &s);
            bfs(s);
            for (i = 1; i <= n; i++)
            {
                if (u[i] == 0)
                {
                    printf("%d is not visited\n", i);
                }
            }
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}