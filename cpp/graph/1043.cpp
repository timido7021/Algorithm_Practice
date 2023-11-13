#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> truth(n);
    vector<vector<int>> adj(50, vector<int>(50, 0));

    int truthNum;
    cin >> truthNum;

    queue<int> Q;

    for (int i = 0; i < truthNum; i++)
    {
        int t;
        cin >> t;
        truth[t - 1]++;
        Q.push(t - 1);
    }

    vector<vector<int>> party;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        party.push_back(vector<int>(num));
        for (auto &elem : party[i])
            cin >> elem;

        auto &P = party[i];

        for (int i = 0; i < num; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                adj[P[i] - 1][P[j] - 1] = 1;
                adj[P[j] - 1][P[i] - 1] = 1;
            }
        }
    }

    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();

        for (int nxt = 0; nxt < n; nxt++)
        {
            if (adj[curr][nxt] == 1 && truth[nxt] != 1)
            {
                truth[nxt] = 1;
                Q.push(nxt);
            }
        }
    }

    int answer = 0;

    for (auto &elem : party)
    {
        int canLie = 1;
        for (auto &e : elem)
        {
            if (truth[e - 1] == 1)
                canLie = 0;
        }
        answer += canLie;
    }

    cout << answer;
}