#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(n, 1e9 + 7);
    vector<list<tuple<int, int>>> adj(n, list<tuple<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int s, e, d;
        cin >> s >> e >> d;
        s--, e--;
        adj[s].push_back({d, e});
    }

    int S, E;
    cin >> S >> E;
    S--, E--;

    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;
    PQ.push({0, S});

    while (!PQ.empty())
    {
        auto [currDist, curr] = PQ.top();
        PQ.pop();

        if (dist[curr] < currDist)
            continue;

        for (auto &[d, nxt] : adj[curr])
        {
            if (dist[nxt] > dist[curr] + d)
            {
                dist[nxt] = dist[curr] + d;
                PQ.push({dist[nxt], nxt});
            }
        }
    }

    cout << dist[E];
}