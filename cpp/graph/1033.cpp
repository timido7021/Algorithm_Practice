#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (a % b)
        return gcd(b, a % b);
    else
        return b;
}

// 같은 컴포넌트끼리 mul 곱하기
void dfs(int curr, vector<vector<int>> &adj, vector<ll> &V, vector<int> &vis, ll mul)
{
    for (auto nxt : adj[curr])
    {
        if (vis[nxt] == 0)
        {
            vis[nxt] = 1;
            V[nxt] *= mul;
            dfs(nxt, adj, V, vis, mul);
            vis[nxt] = 0;
        }
    }
}

// 곱한 수의 gcd로 나눈다.
void dfs_gcd(int curr, vector<vector<int>> &adj, vector<ll> &V, vector<int> &vis, ll g)
{
    for (auto nxt : adj[curr])
    {
        if (vis[nxt] == 0)
        {
            vis[nxt] = 1;
            V[nxt] /= g;
            dfs_gcd(nxt, adj, V, vis, g);
            vis[nxt] = 0;
        }
    }
}

// 1033 boj.kr/1033
int main()
{
    int n;
    cin >> n;

    vector<ll> V(n, 1);
    vector<vector<int>> adj(10, vector<int>());

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        ll p, q;
        cin >> a >> b >> p >> q;

        ll pq_gcd = gcd(p, q);
        p = p / pq_gcd;
        q = q / pq_gcd;

        vector<int> vis(n, 0);

        ll prevA = V[a];
        ll prevB = V[b];

        // 반대편 연결 요소와 비율을 곱한다.

        vis[a] = 1;
        V[a] *= V[b] * p;
        dfs(a, adj, V, vis, V[b] * p);

        vis[b] = 1;
        V[b] *= prevA * q;
        dfs(b, adj, V, vis, prevA * q);

        // 곱한 수의 gcd로 나눈다.
        ll ab_gcd = gcd(prevB * p, prevA * q);

        vector<int> vis2(n, 0);

        V[a] /= ab_gcd;
        vis2[a] = 1;
        dfs_gcd(a, adj, V, vis2, ab_gcd);

        V[b] /= ab_gcd;
        vis2[b] = 1;
        dfs_gcd(b, adj, V, vis2, ab_gcd);

        // 이후 두 연결 요소끼리 합쳐준다.
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        cout << V[i] << ' ';
}