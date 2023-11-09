#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

// 펜윅트리를 업데이트할 때 i의 최하위비트에 1씩 더해가면서 업데이트한다.
void updateFenwick(int idx, ll num, vector<ll> &F, vector<ll> &origin)
{
    ll prev = origin[idx];
    origin[idx] = num;
    while (idx < F.size())
    {
        F[idx] += num - prev;
        idx += (idx & -idx);
    }
    return;
}

// 펜윅트리에서 범위의 누적합을 구할 때 1 ~ (i - 1), 1 ~ j 의값을 구한후 뺀다.
// 1 ~ i는 i에서 i의 최하위 비트만 빼며 구한다.
// 오답노트 : 반환형도 ll로 맞추기...
ll getFenwick(int i, int j, vector<ll> &F)
{
    ll ret = 0;

    while (j > 0)
    {
        ret += F[j];
        j -= (j & -j);
    }

    i--;
    while (i > 0)
    {
        ret -= F[i];
        i -= (i & -i);
    }

    return ret;
}

// 2042 boj.kr/2042
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;

    cin >> n >> m >> k;

    vector<ll> origin(n + 1);

    // 펜윅트리를 사용한다.
    // 펜윅트리의 원리는 1 ~ n인 인덱스를 가진 배열에서
    // f[i] = (i - (i & -i) + 1) ~ i 번의 원소를 더한 값이라는 원리에서 출발한다.
    // i & -i 는 i의 최하위 비트의 수인데 12의 최하위 비트는 1100 -> 100 == 4 이므로,
    // 12 -> 9 10 11 12 의 합이 된다.
    vector<ll> fenwick(n + 1);

    for (int i = 1; i <= n; i++)
    {
        ll num;
        cin >> num;
        // cin >> origin[i];
        updateFenwick(i, num, fenwick, origin);
    }

    for (int i = 0; i < m + k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) // change
            updateFenwick(b, c, fenwick, origin);
        else if (a == 2) // sum
            cout << getFenwick(b, c, fenwick) << '\n';
    }
}