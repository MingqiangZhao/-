#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    
    int res = 0;;
    
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if(!st[j] && (t == - 1 || dist[t] > dist[j]))
                t = j;
                
        if(i && dist[t] == INF) return INF;
        
        if(i) res += dist[t];
        st[t] = true;
        
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
        
    }
    
    return res;
    
}

int main()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof g);
    
    while(m -- )
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    
    if(t == INF) cout << "impossible";
    else cout << t;
    
    return 0;
}
