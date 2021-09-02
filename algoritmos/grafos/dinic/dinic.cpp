#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 500
#define INF 987654321
using namespace std;
typedef long long lld;

struct Node
{
    vector<int> adj;
};
Node graf[MAX_N];

struct Edge
{
    int u, v, cap;
    int flow;
};
vector<Edge> E;

int v, e;
int s, t;
int dist[MAX_N];
int upTo[MAX_N];
int idd = 0;

bool BFS()
{
    for (int i=1;i<=v;i++) dist[i] = -1;
    queue<int> bfs_queue;
    bfs_queue.push(s);
    dist[s] = 0;
    while (!bfs_queue.empty())
    {
        int xt = bfs_queue.front();
        bfs_queue.pop();
        for (int i=0;i<graf[xt].adj.size();i++)
        {
            int currID = graf[xt].adj[i];
            int xt1 = E[currID].v;
            if (dist[xt1] == -1 && E[currID].flow < E[currID].cap)
            {
                bfs_queue.push(xt1);
                dist[xt1] = dist[xt] + 1;
            }
        }
    }
    return (dist[t] != -1);
}

int DFS(int xt, int minCap)
{
    if (minCap == 0) return 0;
    if (xt == t) return minCap;
    while (upTo[xt] < graf[xt].adj.size())
    {
        int currID = graf[xt].adj[upTo[xt]];
        int xt1 = E[currID].v;
        if (dist[xt1] != dist[xt] + 1)
        {
            upTo[xt]++;
            continue;
        }
        int aug = DFS(xt1, min(minCap, E[currID].cap - E[currID].flow));
        if (aug > 0)
        {
            E[currID].flow += aug;
            if (currID&1) currID--; else currID++;
            E[currID].flow -= aug;
            return aug;
        }
        upTo[xt]++;
    }
    return 0;
}

int Dinic()
{
    int flow = 0;
    while (true)
    {
        if (!BFS()) break;
        for (int i=1;i<=v;i++) upTo[i] = 0;
        while (true)
        {
            int currFlow = DFS(s, INF);
            if (currFlow == 0) break;
            flow += currFlow;
        }
    }
    return flow;
}

void addEdge(int u, int v, int cap)
{
    Edge E1, E2;
    
    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;
    
    graf[u].adj.push_back(idd++);
    E.push_back(E1);
    graf[v].adj.push_back(idd++);
    E.push_back(E2);
}

int main()
{
    v = 4, e = 5;
    s = 1, t = 4;
    
    addEdge(1, 2, 40);
    addEdge(1, 4, 20);
    addEdge(2, 4, 20);
    addEdge(2, 3, 30);
    addEdge(3, 4, 10);
    
    printf("%d\n",Dinic());
    
    return 0;
}