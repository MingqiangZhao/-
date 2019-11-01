#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;

struct Edge{
    int a, b, c;
}edges[M];

int n, m, k;
int dist[N];
int backup[N];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    
    dist[1] = 0;
    for (int i = 0; i < k; i ++ )
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++ )
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a] + e.c);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    
    
    for (int i = 0; i < m;  i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    
    bellman_ford();
    
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);
    
    return 0;
}



