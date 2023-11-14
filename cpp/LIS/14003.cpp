#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// boj.kr/14003
int main()
{
    int N;
    cin >> N;

    vector<int> V(N);
    for (auto &elem : V)
        cin >> elem;

    // LIS (N * log N) 방식
    // Lower_bound를 이용해서 해결: 오름차순 정렬된 벡터에서 정렬된 순서를 유지하면서 들어갈 자리
    // boj.kr/12015 와 유사하나 LIS를 출력해야 하므로 최대 길이를 저장
    vector<int> LIS;
    vector<int> LIS_tracking;
    vector<int> LIS_answer;
    for (auto &elem : V)
    {
        auto iter = lower_bound(LIS.begin(), LIS.end(), elem);

        // 들어간 자리의 위치를 Tracking할 벡터에 추가해줌. (1 ~ N)
        LIS_tracking.push_back(iter - LIS.begin() + 1);

        if (iter == LIS.end())
            // 만약 마지막 자리에 넣을 수 있다면 추가함
            LIS.push_back(elem);
        // 주의사항: LIS push_back하면 LIS 벡터의 메모리 구조상 위치가 바뀌므로
        // LIS와 iter는 서로 +, - 연산등을 하면 에러가 발생한다.
        else
            // 교체될 수 있는 자리면 교체함
            *iter = elem;
    }

    // LIS 벡터의 크기가 답.
    int answer = LIS.size();
    cout << answer << '\n';

    // 뒤부터 가장 큰 순서대로 확인
    for (auto it = LIS_tracking.rbegin(); it != LIS_tracking.rend(); it++)
    {
        if (*it == answer)
        {
            answer--;
            LIS_answer.push_back(*(V.rbegin() + (it - LIS_tracking.rbegin())));
            // it가 이동한 만큼 LIS에서 찾아주기.
        }
    }

    // 뒤에서 부터 찾았으므로 뒤집어서 출력
    for (auto it = LIS_answer.rbegin(); it != LIS_answer.rend(); it++)
        cout << *it << ' ';
}