#include <iostream>

using namespace std;

// 간단한 재귀함수 문제.
void moveAt(int from, int to, int height)
{
    if (height == 1)
        cout << from << ' ' << to << '\n';
    else
    {
        moveAt(from, 6 - from - to, height - 1);
        cout << from << ' ' << to << '\n';
        moveAt(6 - from - to, to, height - 1);
    }
}

int pow_2(int n)
{
    if (n == 0)
        return 1;
    else
        return 2 * pow_2(n - 1);
}

// 11729 boj.kr/11729
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    cout << pow_2(n) - 1 << '\n';
    moveAt(1, 3, n);
}