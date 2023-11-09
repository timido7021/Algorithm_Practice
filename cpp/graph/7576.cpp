#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int arr[1010][1010];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// 7576 boj.kr/7576
// 간단한 BFS문제.
int main()
{
    int m, n;
    cin >> m >> n;

    queue<tuple<int, int, int>> Q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                Q.push({0, i, j});
        }
    }
    int answer = 0;
    while (!Q.empty())
    {
        auto [cnt, r, c] = Q.front();
        Q.pop();

        answer = cnt;

        for (int d = 0; d < 4; d++)
        {
            int nr = dy[d] + r, nc = dx[d] + c;
            if (nr >= n || nc >= m || nr < 0 || nc < 0 || arr[nr][nc] == -1 || arr[nr][nc] == 1)
                continue;

            arr[nr][nc] = 1;
            Q.push({cnt + 1, nr, nc});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                answer = -1;
        }
    }
    cout << answer;
}