#include <iostream>
#include <algorithm>

using namespace std;

int dp[1010][3], v[1010][3];

int solve(int curr, int color)
{
    if (curr == 0)
        return v[curr][color];

    else
    {
        int ret = 1 << 29;
        int nxtColor = (color + 1) % 3;

        if (dp[curr - 1][nxtColor] == -1)
            dp[curr - 1][nxtColor] = solve(curr - 1, nxtColor);
        ret = min(ret, dp[curr - 1][nxtColor] + v[curr][color]);

        nxtColor = (nxtColor + 1) % 3;

        if (dp[curr - 1][nxtColor] == -1)
            dp[curr - 1][nxtColor] = solve(curr - 1, nxtColor);
        ret = min(ret, dp[curr - 1][nxtColor] + v[curr][color]);

        return ret;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
            dp[i][j] = -1;
        }

    cout << min({solve(n - 1, 0), solve(n - 1, 1), solve(n - 1, 2)});
}