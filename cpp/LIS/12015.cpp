#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// boj.kr/12015
int main()
{
    int N;
    cin >> N;

    vector<int> V(N);
    for (auto &elem : V)
        cin >> elem;

    // LIS (N * log N) 방식
    // Lower_bound를 이용해서 해결: 오름차순 정렬된 벡터에서 정렬된 순서를 유지하면서 들어갈 자리
    vector<int> LIS;
    for (auto &elem : V)
    {
        auto iter = lower_bound(LIS.begin(), LIS.end(), elem);
        if (iter == LIS.end())
            // 만약 마지막 자리에 넣을 수 있다면 추가함
            LIS.push_back(elem);
        else
            // 교체될 수 있는 자리면 교체함
            *iter = elem;
    }

    // LIS 벡터의 크기가 답.
    cout << LIS.size();
}