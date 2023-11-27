#include <iostream>
#include <vector>

using namespace std;

int rowBit[9];
int colBit[9];
int squareBit[9];
vector<int> A;

// 9가지 영역으로 나누어서 관리한다.
void sudoku(int curr, vector<int> &S)
{
    if (curr == 81)
    {
        if (A.size() == 0)
            A = S;
        return;
    }

    if (S[curr] != 0)
        sudoku(curr + 1, S);

    else
    {
        int y = curr / 9;
        int x = curr % 9;

        for (int i = 1; i <= 9; i++)
        {
            if ((rowBit[y] & (1 << i)) ||
                (colBit[x] & (1 << i)) ||
                (squareBit[(y / 3) * 3 + x / 3] & (1 << i)))
                continue;

            S[curr] = i;
            rowBit[y] |= (1 << i);
            colBit[x] |= (1 << i);
            squareBit[(y / 3) * 3 + x / 3] |= (1 << i);

            sudoku(curr + 1, S);

            S[curr] = 0;
            rowBit[y] &= ~(1 << i);
            colBit[x] &= ~(1 << i);
            squareBit[(y / 3) * 3 + x / 3] &= ~(1 << i);
        }
    }
}

// boj.kr/2580
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    vector<int> Sdk(81);

    for (auto &elem : Sdk)
        cin >> elem;

    for (int i = 0; i < 81; i++)
    {
        int y = i / 9;
        int x = i % 9;
        if (Sdk[i] != 0)
        {
            rowBit[y] |= (1 << Sdk[i]);
            colBit[x] |= (1 << Sdk[i]);
            // (y / 3) * 3 + x / 3
            squareBit[(y / 3) * 3 + x / 3] |= (1 << Sdk[i]);
        }
    }

    sudoku(0, Sdk);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << A[i * 9 + j] << ' ';
        }
        cout << '\n';
    }
}