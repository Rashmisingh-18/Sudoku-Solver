#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool isSafe(int grid[9][9], int num, int i, int j)
{
    for (int x = 0; x < 9; x++)
        if (grid[i][x] == num || grid[x][j] == num)
            return false;

    int sx = (i / 3) * 3, sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
            if (grid[x][y] == num)
                return false;
    }

    return true;
}

bool helper(int grid[9][9], int i, int j)
{
    if (i == 9)
        return true;

    if (j == 9)
        return helper(grid, i + 1, 0);

    if (grid[i][j] != 0)
        return helper(grid, i, j + 1);

    for (int n = 1; n <= 9; n++)
    {
        if (isSafe(grid, n, i, j))
        {
            grid[i][j] = n;
            if (helper(grid, i, j + 1))
                return true;
        }
    }
    grid[i][j] = 0;
    return false;
}

bool SudokuSolve(int grid[N][N])
{
    return helper(grid, 0, 0);
}

void printGrid(int grid[N][N])
{
     for (int i = 0; i < 9; i++){
      for (int j = 0; j < 9; j++){
         if(j == 3 || j == 6)
            cout << " | ";
         cout << grid[i][j] <<" ";
      }
      if(i == 2 || i == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
   cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout<<endl;
        if (SudokuSolve(grid) == true)
            printGrid(grid);
        else
            cout << "No solution exists"<<endl;
    }
}