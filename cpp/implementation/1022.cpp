#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// 1022 https://www.acmicpc.net/problem/1022 소용돌이 예쁘게 출력하기.

int calc(int r, int c)
{
    // 예외 처리
    if (r == 0 && c == 0)
        return 1;

    // 기준이 될 둘레 == n
    int n = max(abs(r), abs(c));
    n--;
    // eg. -2, -1 -> 16, n = 1, A = (2 * n + 1) ^ 2 = 9

    // 시작점 A
    int ret = (2 * n + 1) * (2 * n + 1);

    // 계산은 A + 1부터 시작.
    if (r <= n && c == n + 1)
    {
        // r : n ~ n - (2n + 1) = -n - 1
        return ret + 1 + n - r;
    }
    else if (r == -n - 1 && c <= n)
    {
        // c : n ~ (-n - 1)
        return (ret + 2 * n + 2) + n + 1 - c;
    }
    else if (r >= -n && c == -n - 1)
    {
        // r : -n ~ n + 1
        return (ret + 4 * n + 4) + n + 1 + r;
    }
    else if (r == n + 1 && c >= -n)
    {
        // c : -n ~ n + 1
        return (ret + 6 * n + 6) + n + 1 + c;
    }

    return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // (0, 0) -> 1, (1, 1) -> 9, ... (n, n) -> (2n + 1)^2 = A
    // (n, n+1) -> A + 1 ... (n-{2n+1}, n+1) -> A + 2n + 2
    // (n - {2n + 1}, n - {2n + 1}) -> A + 4n + 4
    // (n + 1, n - {2n + 1}) -> A + 6n + 6
    // (n + 1, n + 1) -> A + 8n + 8 == (2n + 3) ^ 2

    // 위 규칙으로 구현
    // r2 - r1 <= 49, c2 - c1 <= 4 이므로 시간 복잡도는 문제 없음.

    vector<int> answer;

    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            answer.push_back(calc(i, j));
        }
    }

    // 가장 큰 수의 자릿수 구하기.

    int maxDigit = 1;
    int maxNum = *max_element(answer.begin(), answer.end());

    while (maxNum / 10)
    {
        maxNum /= 10;
        maxDigit++;
    }

    for (int i = 0; i < r2 - r1 + 1; i++)
    {
        for (int j = 0; j < c2 - c1 + 1; j++)
        {
            int calcNum = answer[i * (c2 - c1 + 1) + j];
            int calcDigit = 1;

            while (calcNum / 10)
            {
                calcNum /= 10;
                calcDigit++;
            }
            for (int i = 0; i < maxDigit - calcDigit; i++)
                cout << " ";

            cout << answer[i * (c2 - c1 + 1) + j] << ' ';
        }
        cout << '\n';
    }
}