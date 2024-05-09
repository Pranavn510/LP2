#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<int>> graph;
    int n;

    Graph()
    {
        cout << "\nEnter number of vertices: ";
        cin >> n;
        graph.resize(n, vector<int>(n, 0));
    }

    void createGraph()
    {
        cout << "\nEnter matrix: ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }
    }

    void showGraph()
    {
        cout << "\nGraph Matrix: ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims()
    {
        vector<vector<int>> cost(n, vector<int>(n, 0));
        int i, j, k;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 0)
                {
                    cost[i][j] = INT16_MAX;
                }
                else
                {
                    cost[i][j] = graph[i][j];
                }
            }
        }

        vector<int> visited(n, 0);
        vector<int> distance(n, 0);
        vector<int> from(n, 0);
        cout << "\nEnter starting vertex: ";
        int v;
        cin >> v;

        for (int i = 0; i < n; i++)
        {
            distance[i] = cost[v][i];
            from[i] = v;
        }
        visited[v] = 1;
        from[v] = -1;

        int ne = n - 1;
        int mindist = INT_MAX;
        int u;
        int mincost = 0;

        while (ne >= 0)
        {
            // find the minimum dist of unavailabe vertex
            mindist = INT16_MAX;

            for (int i = 0; i <= n - 1; i++)
            {
                if (visited[i] == 0 && distance[i] < mindist)
                {
                    mindist = distance[i];
                    v = i;
                }
            }

            u = from[v];
            cout << "Edge:-> " << v << " " << u << endl;
            visited[v] = 1;
            cout << "v:" << v << endl;
            mincost += cost[v][u];

            // search for shortest path of any other node from v
            for (int i = 0; i < n; i++)
            {
                if (visited[i] == 0 && cost[v][i] < distance[i])
                {
                    distance[i] = cost[v][i];
                    from[i] = v;
                }
            }
            ne--;
        }
        cout << "\nMincost: " << mincost;
    }
};

int main()
{
    Graph grp;
    grp.createGraph();
    grp.showGraph();
    grp.prims();
}

/*
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
*/

/*
Edge:-> 1 0
Edge:-> 3 0
Edge:-> 2 3
Edge:-> 4 2
*/