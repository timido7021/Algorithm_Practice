#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

// boj.kr/14502
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> M(n, vector<int>(m));
    vector<pair<int, int>> possibleWalls;
    vector<pair<int, int>> virus;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
            if (M[i][j] == 2)
                virus.push_back({i, j});
            else if (M[i][j] == 0)
                possibleWalls.push_back({i, j});
        }
    }
    int w = possibleWalls.size();
    int answer = 0;

    for (int i = 0; i < w; i++)
    {
        for (int j = i + 1; j < w; j++)
        {
            for (int k = j + 1; k < w; k++)
            {
                auto arr = {possibleWalls[i], possibleWalls[j], possibleWalls[k]};

                for (auto [r, c] : arr)
                    M[r][c] = 1;

                int A = 0;

                vector<vector<int>> M_temp(M);

                queue<pair<int, int>> Q;
                for (auto elem : virus)
                    Q.push(elem);

                while (!Q.empty())
                {
                    auto [y, x] = Q.front();
                    Q.pop();

                    for (int d = 0; d < 4; d++)
                    {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m || M_temp[ny][nx] == 1 || M_temp[ny][nx] == 2)
                            continue;
                        M_temp[ny][nx] = 2;
                        Q.push({ny, nx});
                    }
                }

                for (auto &elem : M_temp)
                    for (auto &e : elem)
                        if (e == 0)
                            A++;

                answer = max(answer, A);

                for (auto [r, c] : arr)
                    M[r][c] = 0;
            }
        }
    }
    cout << answer;
}