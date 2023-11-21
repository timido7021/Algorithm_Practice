#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // 0 ~ n-1
    cin >> n;

    vector<int> digits(n);
    for (auto &e : digits)
        cin >> e;

    int m;
    cin >> m;

    // greedy. 1~9까지의 숫자 중 최소 비용의 숫자를 A, 0~9를 B라고 하면
    // ABBBBB... 를 구성.

    // 이후 A보다 큰 수 중 가능하다면 앞 자리부터 바꿈.
    // B도 마찬가지.

    int A = -1, temp = 1e9;
    for (int i = 1; i < n; i++)
    {
        if (digits[i] <= temp)
        {
            temp = digits[i];
            A = i;
        }
    }

    int B = -1;
    temp = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (digits[i] <= temp)
        {
            temp = digits[i];
            B = i;
        }
    }

    if (digits[A] > m && B == 0) // 0만 가능할 때.
    {
        cout << 0;
        return 0;
    }

    vector<int> ans;

    if (A != -1 && m >= digits[A])
    {
        ans.push_back(A);
        m -= digits[A];
    }

    if (B != -1)
    {
        while (m >= digits[B])
        {
            ans.push_back(B);
            m -= digits[B];
        }
    }

    int prevA = A;

    for (int i = A + 1; i < n; i++)
    {
        if (m + digits[prevA] >= digits[i])
        {
            m -= digits[i];
            m += digits[prevA];
            prevA = i;
            ans[0] = i;
        }
    }

    for (int i = 1; i < ans.size(); i++)
    {
        int prevB = B;
        for (int j = B + 1; j < n; j++)
        {
            if (m + digits[prevB] >= digits[j])
            {
                m -= digits[j];
                m += digits[prevB];
                prevB = j;
                ans[i] = j;
            }
        }
    }

    for (auto &e : ans)
        cout << e;
}

// 예외 케이스
/*
4
1 49 49 49
40

0

4
1 49 49 49
49

3

4
1 49 49 49
50

30

4
49 1 49 49
40

111...
*/