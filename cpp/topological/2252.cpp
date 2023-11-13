#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// boj.kr/2252
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ind(n + 1);                        // indegree - 들어오는 간선의 수
    vector<vector<int>> adj(n + 1, vector<int>()); // 간선 리스트

    for (int i = 0; i < m; i++)
    {
        int a, b; // a -> b
        cin >> a >> b;
        ind[b]++;
        adj[a].push_back(b);
    }

    queue<int> Q;

    for (int i = 1; i <= n; i++)
        if (ind[i] == 0)
            Q.push(i);

    // 위상정렬
    while (!Q.empty())
    {
        int curr = Q.front();
        cout << curr << ' ';
        Q.pop();

        for (auto &nxt : adj[curr])
        {
            ind[nxt]--;
            if (ind[nxt] == 0)
                Q.push(nxt);
        }
    }
}