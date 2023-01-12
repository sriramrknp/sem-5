#include <bits/stdc++.h>
using namespace std;

#define Inf 9999
#define max 10

void dijkstra(int G[max][max], int n, int str_node)
{
    int cost[max][max], dis[max], pred[max];
    int vis[max], count, min_dis, nxt_node, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = Inf;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        dis[i] = cost[str_node][i];
        pred[i] = str_node;
        vis[i] = 0;
    }
    dis[str_node] = 0;
    vis[str_node] = 1;
    count = 1;
    while (count < n - 1)
    {
        min_dis = Inf;
        
        for (i = 0; i < n; i++)
        {
            if (dis[i] < min_dis && !vis[i])
            {
                min_dis = dis[i];
                nxt_node = i;
            }
        }
        
        vis[nxt_node] = 1;
        for (i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (min_dis + cost[nxt_node][i] < dis[i])
                {
                    dis[i] = min_dis + cost[nxt_node][i];
                    pred[i] = nxt_node;
                }
            }
        }
        count++;
    }

   
    for (i = 0; i < n; i++)
    {
        if (i != str_node)
        {
            cout << "Distance of node " << i << " " << dis[i];
            cout << "\nThe route or path followed -- " << i;

            j = i;
            do
            {
                j = pred[j];
                cout << " - " << j;
            } while (j != str_node);
            cout << '\n';

        }
    }

    cout << "\nThe last path is the minimum path to be followed\n";
}

int main()
{
    int G[max][max], i, j, n, u;
    cout << "Enter num of vertices: ";
    cin >> n;

    // 0 2 0 1
    // 2 0 3 7
    // 0 3 0 11
    // 1 7 11 0

    cout << "Enter the matrix: \n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }

    cout << "\nEnter the source node: ";
    cin >> u;
    dijkstra(G, n, u);
    
    return 0;
}