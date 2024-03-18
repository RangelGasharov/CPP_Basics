#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> Node;
typedef vector<vector<Node>> Graph;

vector<int> dijkstraShortestPath(Graph &graph, int start, int end)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    priority_queue<Node, vector<Node>, greater<Node>> priorityQueue;

    dist[start] = 0;
    priorityQueue.push({start, 0});

    while (!priorityQueue.empty())
    {
        int u = priorityQueue.top().first;
        priorityQueue.pop();

        if (u == end)
        {
            break;
        }

        visited[u] = true;

        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;

                priorityQueue.push({v, dist[v]});
            }
        }
    }

    vector<int> path;
    int v = end;
    while (v != start)
    {
        path.push_back(v);

        for (auto &neighbor : graph[v])
        {
            if (dist[v] - neighbor.second == dist[neighbor.first])
            {
                v = neighbor.first;
                break;
            }
        }
    }

    path.push_back(start);
    reverse(path.begin(), path.end());

    if (dist[end] == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dist[end] << endl;
        for (int node : path)
        {
            cout << node + 1 << " ";
        }
        cout << endl;
    }

    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstraShortestPath(graph, 0, n - 1);

    return 0;
}
