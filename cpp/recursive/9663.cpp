#include <iostream>
#include <cmath>

using namespace std;

int n; // N-Queen
int arr[16];

int solveNQueen(int curr)
{
    if (curr == n)
        return 1;

    int ret = 0;

    for (int col = 0; col < n; col++)
    {
        bool possible = true;
        for (int row = 0; row < curr; row++)
        {
            possible &= !(arr[row] == col);
            possible &= !(abs(arr[row] - col) == abs(row - curr));
            // 같은 열에 있거나 기울기가 -1, 1인 대각선 상에 존재하면 제외.
        }
        if (possible)
        {
            arr[curr] = col;
            ret += solveNQueen(curr + 1);
            arr[curr] = 0;
        }
    }

    return ret;
}

// boj.kr/9663
int main()
{
    cin >> n;

    // n x n 판위에 i(= 0 ~ n-1)행에 배치하게된다.
    // 따라서 일차원 배열에 표현할 수 있다.
    // arr[i] - i행 에 배치한 열 (1, 2)=>arr[1]:2

    cout << solveNQueen(0);
}