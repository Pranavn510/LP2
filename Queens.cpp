#include <bits/stdc++.h>
using namespace std;

void addDots(int n, vector<vector<int>> &board, vector<vector<string>> &ans)
{
    vector<string> temp;
    for (int i = 0; i < n; i++)
    {
        string op;
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                op.push_back('Q');
            }
            else
            {
                op.push_back('.');
            }
        }
        temp.push_back(op);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{

    int x = row;
    int y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--; // same row behind
    }
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--; // diagonal up;
    }

    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--; // down diagonal
    }

    return true;
}
void solve(int col, int n, vector<vector<int>> &board, vector<vector<string>> &ans)
{
    if (col == n)
    {
        addDots(n, board, ans);
        return; // base condition;
    }

    // solve for only row of one col.
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, n, board, ans);
            // bactrack
            board[row][col] = 0;
        }
    }
}

void print(int n, vector<vector<string>> &solution)
{

    for (auto it : solution)
    {
        cout << "-----------------" << endl;
        for (auto x : it)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }
}

int main()
{
    int n;
    cout << "enter the No of Queens ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<string>> ans;

    solve(0, n, board, ans);
    print(n, ans);

    return 0;
}