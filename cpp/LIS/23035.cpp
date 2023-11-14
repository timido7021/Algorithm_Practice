#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int t;
    cin >> t;

    vector<pair<int, int>> cats;

    for (int i = 0; i < t; i++)
    {
        int r, c;
        cin >> r >> c;
        // "범위 밖에 고양이가 존재할 수 있다."
        if (r <= n && c <= m)
            cats.push_back({r, c});
    }

    // LIS인 이유?
    // (r1, c1) 에서 (r2, c2)를 가기위해
    // r1<=r2 && c1<=c2 이여야 한다. 즉 최대한 많이 방문하기위해서는 정렬 후에 LIS를 만족하는 순으로 가는 것이 좋다.
    // 정렬한 후는 r1==r2일때 c1 <= c2이므로
    // 비교 함수를 c1 > c2를 만족하면 대체하도록 한다.

    sort(cats.begin(), cats.end());

    vector<pair<int, int>> LIS;
    for (auto &elem : cats)
    {
        auto iter = lower_bound(LIS.begin(), LIS.end(), elem,
                                [](pair<int, int> a, pair<int, int> b)
                                {
                                    if (a.first > b.first || a.second > b.second)
                                        return false;
                                    else
                                        return true;
                                });
        if (iter == LIS.end())
            LIS.push_back(elem);
        else
            *iter = elem;
    }

    cout << LIS.size();
}