#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
using ll = long long;

// WRONG. DP[i][j] ~ DP[j+1][k]에 대한 경우를 구하지 못함.
int solve(int a, int b, vector<vector<int>> &DP, vector<tuple<int, int>> &M)
{
    if (a == b)
        return DP[a][b] = 0;
    else
    {
        if (DP[a][b] != -1)
            return DP[a][b];

        auto &[a_r, a_c] = M[a];
        auto &[b_r, b_c] = M[b];

        if (DP[a + 1][b] == -1)
            DP[a + 1][b] = solve(a + 1, b, DP, M);
        int leftFirst = DP[a + 1][b] + a_r * a_c * b_c;

        if (DP[a][b - 1] == -1)
            DP[a][b - 1] = solve(a, b - 1, DP, M);
        int rightFirst = DP[a][b - 1] + a_r * b_r * b_c;

        DP[a][b] = min(leftFirst, rightFirst);
        return DP[a][b];
    }
}

// 11049 boj.kr/11049
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    // DP[i][j] = i ~ j를 곱하는 최소 수.
    // DP[i][j] = min(DP[i + 1][j] + r * c * c, DP[i][j - 1] + r * r * c)
    // DP[i][i] = 0;
    // DP[0][n-1]이 Answer.
    // DP[i][j] ~ DP[j+1][k] 의 경우도 생각해봐야함.
    // 2 ^ 40 을 최대값으로 설정해서 2^32 에서 오버플로우가 안나게함.
    vector<vector<ll>> dp(n, vector<ll>(n, 1LL << 40));

    vector<tuple<ll, ll>> mat(n);

    for (auto &[r, c] : mat)
        cin >> r >> c;

    // cout << solve(0, n - 1, dp, mat);

    for (int i = 0; i < n; i++) // 0 ~ 0 + i
    {
        for (int j = 0; i + j < n; j++) // (j, i + j)
        {
            int s = j, e = i + j;
            if (s == e)
                dp[s][e] = 0;
            else if (s + 1 == e)
            {
                auto &[s_r, s_c] = mat[s];
                auto &[e_r, e_c] = mat[e];
                dp[s][e] = s_r * s_c * e_c;
            }
            else
            {
                for (int k = s; k < e; k++) // (j, i + j)
                {
                    auto &[s_r, s_c] = mat[s];
                    auto &[k_r, k_c] = mat[k];
                    auto &[e_r, e_c] = mat[e];
                    dp[s][e] = min(dp[s][e],
                                   dp[s][k] + dp[k + 1][e] + s_r * k_c * e_c);
                }
            }
        }
    }
    cout << dp[0][n - 1];
}