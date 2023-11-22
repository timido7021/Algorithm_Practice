#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

using tiii = tuple<long long, int, int>;

int ufFind(int child, vector<int> &uf)
{
    int &pa = uf[child]; // 상위 노드 조사
    if (pa == child)     // 같으면 최상위 노드
        return pa;
    else
        return pa = ufFind(pa, uf); // 최상위 노드의 값을 전파
}

void ufMerge(int p1, int p2, vector<int> &uf)
{
    p1 = ufFind(p1, uf);
    p2 = ufFind(p2, uf);

    if (p1 > p2)
    {
        int temp = p1;
        p1 = p2;
        p2 = temp;
    }

    uf[p2] = p1;
}

// 1197 boj.kr/1197
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int v, e;
    cin >> v >> e;

    vector<int> uf(v);
    priority_queue<tiii, vector<tiii>, greater<>> PQ;

    // 크루스칼 알고리즘, 가장 가중치가 낮은 간선부터 연결한다.
    // 유니온 파인드 자료구조도 필요하다.
    // E log E * (union-find 찾기+병합 시간복잡도: O(n) 이하)

    for (int i = 0; i < v; i++)
        uf[i] = i;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        PQ.push({c, a - 1, b - 1});
    }

    long long ans = 0;

    while (!PQ.empty())
    {
        long long weight;
        int a, b;
        tie(weight, a, b) = PQ.top();
        PQ.pop();

        if (ufFind(a, uf) != ufFind(b, uf))
        {
            ans += weight;
            ufMerge(a, b, uf);
        }
    }

    cout << ans;
}