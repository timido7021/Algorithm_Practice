#include <iostream>
#include <algorithm>

using namespace std;

// 1806 https://www.acmicpc.net/problem/1806 부분합.
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, s;
    cin >> n >> s;

    vector<int> V(n), presum(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
        presum[i + 1] = presum[i] + V[i];
        // V[i ~ j] = presum[j + 1] - presum[i]
    }

    // 자연수니까 투 포인터를 사용함.
    // l ~ r 사이의 범위를 조사한다.
    // r > n 이면 l의 값에 상관없이 s보다 작기 때문에 종료.

    int l = 0, r = 1, result = 1e9 + 7;
    while (r <= n)
    {
        if (presum[r] - presum[l] >= s)
        {
            result = min(result, r - l);
            l++;
        }
        else
            r++;
    }

    if (result == 1e9 + 7)
        result = 0;
    cout << result;
}