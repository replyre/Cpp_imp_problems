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

void display(vector<vector<bool>> board)
{
    for (auto r : board)
    {
        for (auto c : r)
        {
            if (c)
                cout << "K"
                     << " ";
            else
                cout << "X"
                     << " ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<bool>> board, int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size())
    {
        return true;
    }
    return false;
}
bool isSafe(vector<vector<bool>> board, int row, int col)
{
    if (isValid(board, row - 1, col - 2))

        if (board[row - 1][col - 2])
            return false;
    if (isValid(board, row - 1, col + 2))
        if (board[row - 1][col + 2])
            return false;
    if (isValid(board, row - 2, col - 1))
        if (board[row - 2][col - 1])
            return false;
    if (isValid(board, row - 2, col + 1))
        if (board[row - 2][col + 1])
            return false;

    return true;
}

void NKnight(vector<vector<bool>> board, int row, int col, int target)
{
    if (target == 0)
    {
        display(board);
        cout << endl;
    }
    if (row == board.size() - 1 && col == board.size())
    {
        return;
    }

    if (col == board.size())
    {
        NKnight(board, row + 1, 0, target);
        return;
    }

    if (isSafe(board, row, col))
    {
        board[row][col] = true;
        NKnight(board, row, col + 1, target - 1);
        board[row][col] = false;
    }

    NKnight(board, row, col + 1, target);
}

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t; while(_t--)
    vector<vector<bool>> board = {
        {false, false, false},
        {false, false, false},
        {false, false, false},
    };

    NKnight(board, 0, 0, 4);

    return 0;
}