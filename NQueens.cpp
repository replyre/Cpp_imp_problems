#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);

void display(vector<vector<bool>> board)
{
    for (auto row : board)
    {
        for (auto e : row)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(vector<vector<bool>> board, int row, int col)
{
    // check vertical
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }

    // check left
    int maxLeft = min(row, col);
    for (int i = 1; i <= maxLeft; i++)
    {
        if (board[row - i][col - i])
            return false;
    }

    // check Right
    int disRight = board.size() - col - 1;
    int maxRight = min(row, disRight);
    for (int i = 1; i <= maxRight; i++)
    {
        if (board[row - i][col + i])
            return false;
    }

    return true;
}

int NQueens(vector<vector<bool>> board, int row)
{

    if (row == board.size())
    {
        display(board);
        return 1;
    }
    int count = 0;

    for (int col = 0; col < board.size(); col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = true;
            count += NQueens(board, row + 1);
            board[row][col] = false;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<bool>> board = {
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
    };
    NQueens(board, 0);
    return 0;
}
